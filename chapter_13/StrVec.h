/*
* 自定义类StrVec来实现标准库中vector容器的简化版本。StrVec不使用模板，它只用于存储string类型的元素。
* 我们将使用allocator来获取原始内存，并使用allocator的construct函数和destroy函数来创建和销毁对象。
* 我们的类将不使用迭代器而使用指针来访问元素。
*
* StrVec包含的成员：
* 变量：
*   sting *element, string *first_free, string *cap, allocator<string> alloc
* 公共函数：
*   push_back(arg), string *begin(), string *end(), void reserv(n), 
*   size_t capacity(), size_t size(), void resize(n)/void resize(n, t)
* 私有函数：
*   pair<string*, string*> alloc_n_copy(string *b, string *e) 
*       将参数指定范围内的元素拷贝到新的内存中，返回一个pair对象，其first成员为指向拷贝后首元素的指针，
*       second成员是库函数uninitianized_copy函数的返回值，它是指向拷贝后尾元素之后的位置指针。
*   void check_alloc() 检查是否还有剩余内存（至少能再容纳一个元素），如果没有则：
*       1、如果capacity()等于0，则调用reallocate分配能容纳一个元素的内存；
*       2、如果capacity()大于0，则调用reallocate重新分配长度为原来一倍的新内存。
*   void reallocate(size_t newCapacity) 重新分配一块指定大小的新内存，
*       并将所有元素移动（不是拷贝）到新内存中，移动后指向原内存的指针将无法访问元素。
*   void free() 释放全部内存
*/
#ifndef MY_STRVEC_H
#define MY_STRVEC_H
#include <memory>
#include <string>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const initializer_list<string>);
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;               // 移动构造函数
    ~StrVec() { free(); }
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&&) noexcept;   // 移动赋值运算符
    void push_back(const string&);
    void resize(size_t);                
    void resize(size_t, const string&);
    void reserve(size_t);
    inline size_t size() const { return first_free - elements; }
    inline size_t capacity() const { return cap - elements; }
    inline string *begin() const { return elements; }
    inline string *end() const { return first_free; }
private:
    string *elements;       // 指向内存中首元素的位置
    string *first_free;     // 指向末尾元素后的第一个未构造任何元素的位置
    string *cap;            // 指向内存的最后一个位置的下一位
    static allocator<string> alloc;  // 静态类型的allocator
    // 拷贝参数指定范围内的元素，返回的是由首元素指针和尾后指针组成的pair对象
    pair<string*, string*> alloc_n_copy(const string*, const string*);   
    // 释放全部内存
    void free();
    // 检查是否还有剩余内存，如果没有就重新分配更大的内存
    void check_alloc();
    // 重新分配指定大小的内存，并将原来的元素移动到新内存中，最后释放原内存
    // 如果新内存大小比原来小，则只移动其能容纳的元素
    void reallocate(size_t);
};

allocator<string> StrVec::alloc;

// 接受initializer_list<string>类型的字符串数组为参数的构造函数
StrVec::StrVec(initializer_list<string> lst)
{
    auto newdata = alloc_n_copy(lst.begin(), lst.end()); // 创建与lst等长的内存，并将元素拷贝到新内存中
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 拷贝构造函数
StrVec::StrVec(const StrVec& sv) 
{
    auto newdata = alloc_n_copy(sv.elements, sv.first_free);
    elements = newdata.first;
    first_free = cap = newdata.second;
}


// 移动构造函数
StrVec::StrVec(StrVec &&sv) noexcept : 
    elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
{
    sv.elements = sv.first_free = sv.cap = nullptr;   // 确保其运行析构函数的安全
}

// 移动赋值运算符
inline StrVec &StrVec::operator=(StrVec &&rsv) noexcept
{
    if(this != &rsv) {  // 确保自赋值的正确
        free();         // 释放左值的内存
        elements = rsv.elements;
        first_free = rsv.first_free;
        cap = rsv.cap;
        // 将rsv置于可析构状态
        rsv.elements = rsv.first_free = rsv.cap = nullptr;  
    }
    return *this;
}

// 拷贝赋值运算符
inline StrVec &StrVec::operator=(const StrVec &rsv)
{
    auto newdata = alloc_n_copy(rsv.begin(), rsv.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 向容器末尾添加元素
inline void StrVec::push_back(const string &s) 
{
    check_alloc();                   // 确保容器由足够的内存，可以容纳至少一个新元素
    alloc.construct(first_free++, s);
}

// 对StrVect进行拷贝、赋值操作时用到的工具类
inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto p = alloc.allocate(e - b);
    auto dest = p;
    return {p, uninitialized_copy_n(b, e - b, dest)};
}

inline void StrVec::free()
{
    // for (auto p = elements; p != first_free; ++p) {
    //     alloc.destroy(p);
    // }
    // 逐个销毁元素，可以使用一般的for循环，也可以使用for_each函数加lambda语句
    for_each(elements, first_free, [](string &s) { alloc.destroy(&s); });
    alloc.deallocate(elements, capacity());
    elements = first_free = cap = nullptr;   // 将指针置为空，避免出现指针空悬
}

// 检验内存是否还能容纳至少一个元素，如果不能，则创建更大的内存
inline void StrVec::check_alloc()
{
    if (size() == capacity()) {
        size_t newCapacity = size() ? size() * 2 : 1; 
        reallocate(newCapacity);     // 将原来的元素移动到新得内存中
    }
}

// 重新分配指定大小的内存，将原来的元素移动到新内存中。
// 如果新内存大小小于旧内存，则多余的元素将被丢弃
inline void StrVec::reallocate(size_t newCapacity)
{
    auto newMemery = alloc.allocate(newCapacity);
    auto p = newMemery;
    auto elem = elements;
    while (elem != elements + size() && 
        p != newMemery + newCapacity) 
    {    // 传入库函数move给construct函数，将调用string的移动构造函数。
        alloc.construct(p++, std::move(*elem++));  // 移动后原来指针所指位置的string将不存在
    }
    free();         // 释放旧内存
    elements = newMemery;
    first_free = p;
    cap = elements + newCapacity;
}

// 重置元素数量为n
inline void StrVec::resize(size_t n)
{
    if (n > size()) {
        while (n > size()) {     // 如果n大于size()，将对新添加的元素默认初始化
            push_back(string());
        }
    }
    if (n < size()) {
        while (n < size()) {     // 如果n小于size()，将丢弃多余的元素
            alloc.destroy(--first_free);
        }
    }
}

// 重置元素数量为n，并将新添加的元素初始化为s
inline void StrVec::resize(size_t n, const string &s)
{
    if (n > size()) {
        while (n > size()) {
            push_back(s);
        }
    }
    if (n < size()) {
        while (n < size()) {
            alloc.destroy(--first_free);
        }
    }
}

// 保证内存至少可以容纳指定数量的元素
inline void StrVec::reserve(size_t n)
{
    if (capacity() < n) {    // 如果容量不够，则重新分配指定的容纳，否则什么也不做
        reallocate(n);
    }
}
#endif

