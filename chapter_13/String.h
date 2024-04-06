/*
* 自定义类String实现标准库string的简化版本。该类至少应该有一个默认构造函数和一个接受C风格字符串指针的构造函数。
* 我们使用allocator来分配String所需内存。
*/
#ifndef MY_STRING_H
#define MY_STRING_H
#include <memory>
#include <algorithm>
#include <ostream>

using namespace std;

class String {
friend ostream &operator<<(ostream&, const String&);
public:
    String() : ch(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char[]);   // 从字面值常量到String的转换，都要依然该构造函数
    String(const String&);
    String(String&&) noexcept;     // 移动构造函数
    ~String() { free(); }
    String &operator=(String &&) noexcept;   // 移动赋值运算符
    String &operator=(const String&);        // 拷贝赋值运算符
    String &append(const String&);
    void push_back(const char);
    void pop_back();
    const char &at(size_t);
    // 一些简单的函数直接定义在类内部
    inline char *begin() const { return ch; }
    inline char *end() const { return first_free; }
    inline size_t size() const { return first_free - ch; }
    inline size_t capacity() const { return cap - ch; }
private:
    char *ch;
    char *first_free;
    char *cap;
    static allocator<char> alloc;
    void free();
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void reallocte(size_t);
    void check_alloc();
};

allocator<char> String::alloc;     // 必须在类外部初始化静态数据成员

// 接受C风格字符串指针的拷贝构造函数
// 数组名其实是指向数组首元素的指针
String::String(const char arr[]) : 
    ch(nullptr), first_free(nullptr), cap(nullptr)  // 必须首先给这三个数据成员默认初始化，再执行函数体
{
    cout << "C style copy constructer: " << arr << endl;
    while (*arr != '\0') {
        push_back(*arr++);
    }
}

// 拷贝构造函数
String::String(const String &s)
{
    cout << "copy constructer: " << s << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    ch = newdata.first;
    first_free = cap = newdata.second;
}

// 移动构造函数
String::String(String &&s) noexcept : 
    ch(s.ch), first_free(s.first_free), cap(s.cap)
{
    cout << "move constructer: " << s << endl;
    s.ch = s.first_free = s.cap = nullptr;    // 确保参数s运行析构函数的安全性
}

// 重载<<运算符，以便可以使用<<运算符直接将String输出到控制台
ostream &operator<<(ostream &os, const String &s)
{
    for (auto p = s.begin(); p != s.end(); ++p) {
        os << *p;
    }
    return os;
}

// 移动赋值运算符，并保证自赋值的正确
inline String &String::operator=(String &&rs) noexcept
{
    if (this != &rs) { // 如果是自赋值，则什么也不做
        cout << "move assignment operator: " << rs << endl;
        free();
        ch = rs.ch;
        first_free = rs.first_free;
        cap = rs.cap;
        // 将rsv置于可析构状态
        rs.ch = rs.first_free = rs.cap = nullptr;
    }
    return *this;
}

// 拷贝赋值运算符
inline String &String::operator=(const String &rs)
{
    cout << "copy assignment operator: " << rs << endl;
    auto newdata = alloc_n_copy(rs.begin(), rs.end());
    ch = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

// 将参数给定的String添加字符串的末尾，返回连接后的String的引用
inline String &String::append(const String &s)
{
    if (capacity() < s.size()) {
        reallocte(s.size());
    }
    for_each(s.begin(), s.end(), [this](char ch) { push_back(ch); });
    return *this;
}

// 将给定的字符添加到String末尾
inline void String::push_back(const char ch)
{
    check_alloc();     // 保证内存容量至少能再多容纳一个字符
    alloc.construct(first_free++, ch);   // 在字符串的末尾构造一个字符元素
}

// 移除字符串末尾字符
inline void String::pop_back()
{
    alloc.destroy(--first_free);   // 销毁末尾元素
}

// 返回指定下标位置的字符的只读引用
inline const char &String::at(size_t index)
{
    if (index >= size()) {
        throw out_of_range("The index out of range!");
    }
    return *(ch + index);
}

// 释放内存
inline void String::free()
{
    for_each(ch, first_free, [](char c) { alloc.destroy(&c); });  // 销毁所有字符
    alloc.deallocate(ch, capacity());                // 释放内存
    ch = first_free = cap = nullptr;
}

// 分配内存并将指定范围的元素拷贝到新内存中
// 返回first成员为首元素指针，second成员为尾后指针的pair对象
inline pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto newMemory = alloc.allocate(e - b);     // 分配新的内存
    auto dest = newMemory;
    return {newMemory, uninitialized_copy_n(b, e - b, dest)}; // 将b~e范围内的元素拷贝到新内存中，返回pair对象 
}

// 为String重新分配内存，将元素从旧空间移动到新空间
inline void String::reallocte(size_t newCapacity) 
{
    auto newMemory = alloc.allocate(newCapacity);     // 分配新的内存
    auto dest = newMemory;
    auto elem = ch;
    while (dest != newMemory + newCapacity && elem != first_free) {
        alloc.construct(dest++, std::move(*elem++));   // 调用Charactor类的移动构造函数，将字符移动到新内存中
    }
    free();        // 释放旧内存
    ch = newMemory;
    first_free = dest;
    cap = newMemory + newCapacity;
}

// 检查内存空间，确保至少可以再添加一个新元素
// 如果内存已经用完，就分配更大的一块新内存
inline void String::check_alloc()
{
    if (capacity() == size()) {
        size_t newCapacity = size() ? size() * 2 : 1;
        reallocte(newCapacity);
    }
}
#endif