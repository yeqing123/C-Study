#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <iostream>

using namespace std;

class StrBlobPtr;   // 提前声明StrBlobPtr类
class StrBlob {
// 声明友元
friend class StrBlobPtr;
friend bool operator==(const StrBlob&, const StrBlob&);
friend bool operator!=(const StrBlob&, const StrBlob&);
friend bool operator<(const StrBlob&, const StrBlob&);
friend bool operator<=(const StrBlob&, const StrBlob&);
friend bool operator>(const StrBlob&, const StrBlob&);
friend bool operator>=(const StrBlob&, const StrBlob&);
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> li);
    bool empty();
    size_type size() const;
    // 访问元素
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    // 删除和添加元素
    void push_back(const string&);
    // 右值引用版本的push_back
    void push_back(string &&);
    void pop_back();
    // 返回指向首个元素的StrBlobPtr对象
    StrBlobPtr begin() const;
    // 返回指向末尾元素下一位的StrBlobPtr对象
    StrBlobPtr end() const;
    // 重载下标运算符
    string &operator[] (size_t n);
    const string &operator[] (size_t n) const;
private:
    shared_ptr<vector<string>> data;
    bool check(size_type index, const string&) const;
};

// 默认构造函数
inline StrBlob::StrBlob() {
    data = make_shared<vector<string>>();
}

inline StrBlob::StrBlob(initializer_list<string> li) {
    data = make_shared<vector<string>>(li);
}

inline bool StrBlob::check(size_type index, const string &msg) const {
    // 如果下标index越界，就抛出一个异常
    if (index >= data->size()) {
        throw out_of_range(msg);
    }
}

inline bool StrBlob::empty() {
    return data->empty();
}

inline StrBlob::size_type StrBlob::size() const {
    return data->size();
}

inline string& StrBlob::front() {
    // 如果vector为空，会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

// const版本
inline const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
inline const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::push_back(const string &s) {
    data->push_back(s);
}

// 完成13章练习55，添加一个右值引用版本的push_back
inline void StrBlob::push_back(string &&s)
{
    data->push_back(std::move(s));   // 将s变为右值，才能调用vector的右值引用版本的push_back
}

inline void StrBlob::pop_back() {
    data->pop_back();
}

inline string &StrBlob::operator[] (size_t n)
{
    return data->at(n);
}

inline const string &StrBlob::operator[] (size_t n) const
{
    return data->at(n);
}

// 判断两个StrBolb对象是否相等，即它们保存的vector相等
bool operator==(const StrBlob &rsb, const StrBlob &lsb)
{
    return *rsb.data == *lsb.data;
}

// 判断两个StrBolb对象是否不相等
bool operator!=(const StrBlob &rsb, const StrBlob &lsb)
{
    return !(rsb == lsb);
}

// 重载关系运算符
bool operator<(const StrBlob &r, const StrBlob &l)
{
    return *r.data < *l.data;
}

bool operator<=(const StrBlob &r, const StrBlob &l)
{
    return *r.data <= *l.data;
}
bool operator>(const StrBlob &r, const StrBlob &l)
{
    return *r.data > *l.data;
}
bool operator>=(const StrBlob &r, const StrBlob &l)
{
    return *r.data >= *l.data;
}



// 实现一个指针类，它可以绑定一个StrBlob对象，指向其所绑定对象中的某个元素，并防止用户访问不存在的元素。
// 它与绑定的StrBlob对象之间是数据的“弱”共享关系，即绑定一个对象并不会增加shared_ptr指针引用计数的递增，也不影响内存的释放。
class StrBlobPtr {
// 声明友元函数
friend bool eq(const StrBlobPtr&, const StrBlobPtr&);  // 判断两个StrBlobPtr是否相等
friend bool neq(const StrBlobPtr&, const StrBlobPtr&); // 判断两个StrBlobPtr是否不相等
// 重载运算符
friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);  
friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);  
friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);  
friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);  
friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);  
friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);  
friend StrBlobPtr operator+(const StrBlobPtr&, int);  
friend StrBlobPtr operator-(const StrBlobPtr&, int);  
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &sb, size_t index = 0) : wptr(sb.data), curr(index) {}
    string &deref();     // 解引用
    StrBlobPtr &incr();       // 当前位置递增一位
    StrBlobPtr &incr(int);    // 当前位置递增指定数量
    StrBlobPtr &decr();       // 当前位置递减一位
    StrBlobPtr &decr(int);    // 当前位置递减指定数量
    string &operator[] (size_t n);   // 重载下标运算符
    const string &operator[] (size_t n) const; // const版本
    // 重载前置递增/递减运算符，返回对象的引用
    StrBlobPtr &operator++();       
    StrBlobPtr &operator--();      
    // 重载后置递增/递减运算符，返回对象原来的拷贝 
    StrBlobPtr operator++(int);    
    StrBlobPtr operator--(int);
    // 重载复合运算符
    StrBlobPtr &operator+=(int);    
    StrBlobPtr &operator-=(int);    
    //  重载解引用运算符和箭头运算符
    string &operator*() const;
    string *operator->() const;
private:
    size_t curr;              // 指向元素的当前位置
    weak_ptr<vector<string>> wptr;
    // 检查当前位置是否合法
    shared_ptr<vector<string>> check(size_t, const string&) const;
};

// StrBlob中的begin和end函数要写在StrBlobPtr类的定义之后
inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t curr, const string &msg) const
{
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound StrBlob");
    }
   
    if (curr >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

inline string &StrBlobPtr::deref()
{
    auto sptr = check(curr, "dereference past end");
    return (*sptr)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::incr(int off)
{
    curr += off;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr()
{
    --curr;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr(int off)
{
    curr -= off;
    return *this;
}

inline string &StrBlobPtr::operator[] (size_t n)
{
    auto sptr = wptr.lock();
    return sptr->at(n);
}

inline const string &StrBlobPtr::operator[] (size_t n) const
{
    auto sptr = wptr.lock();
    return sptr->at(n);
}

// 前置递增运算符
inline StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// 前置递减运算符
inline StrBlobPtr &StrBlobPtr::operator--()
{
    check(curr, "decrement past begin of StrBlobPtr");
    --curr;
    return *this;
}

// 后置递增运算符
inline StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

// 后置递减运算符
inline StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

// 重载复合运算符
inline StrBlobPtr &StrBlobPtr::operator+=(int off)
{
    curr += off;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::operator-=(int off)
{
    curr -= off;
    return *this;
}

string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];     // 返回curr位置的元素
}

string *StrBlobPtr::operator->() const
{
    return & this->operator*();   // 不做任何实际操作，调用解引用运算符，返回元素得到地址
}

bool eq(const StrBlobPtr &l, const StrBlobPtr &r)
{
    // 获取各自所指序列的shared_ptr指针
    auto lp = l.wptr.lock();     
    auto rp = r.wptr.lock();
    // 如果两个指针都指向同一个序列，并且当前位置相等；
    // 或者两个指针都为空，则返回true。否则返回false
    if (lp == rp && l.curr == r.curr) {
        return true;
    } else  {
        return false;
    }

    return false;
}

bool neq(const StrBlobPtr &l, const StrBlobPtr &r)
{
    return !eq(l, r);
}

bool operator==(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    // weak_ptr指针不能直接访问对象，
    // 必须调用lock函数检查其指向的对象是否存在，
    // 如果存在返回指向对象的shared_ptr指针，否则返回一个空的shared_ptr指针。
    auto l = lp.wptr.lock();     
    auto r = rp.wptr.lock();
    // 若两个智能指针均为空，或者都指向一个序列中的同一个元素，则返回true
    if (r == l) {
        return !r || rp.curr == lp.curr;
    }
    return false;
}

bool operator!=(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    return !(rp == lp);
}

bool operator<(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    auto l = lp.wptr.lock();     
    auto r = rp.wptr.lock();
    if (l == r) {          // 首先保证两个指针指向同一个vector对象，然后比较两个指针的位置即可
        return r && rp.curr < lp.curr;
    }
    return false;
}  

bool operator<=(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    auto l = lp.wptr.lock();     
    auto r = rp.wptr.lock();
    if (l == r) {          // 首先保证两个指针指向同一个vector对象，然后比较两个指针的位置即可
        return r && rp.curr <= lp.curr;
    }
    return false;
}  

// 关于>和>=的重载有一个bug，当符号左侧对象的curr执行了减法运算结果小于0时，
// 因为curr是无符号类型，所以就会成为一个很大的正数，>和>=运算符就会返回true。
// 从而产生错误的判断结果！
// 内置的指针类型不会出现这种问题，推断应该是用有符号类型记录指针位置的。
bool operator>(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    auto l = lp.wptr.lock();     
    auto r = rp.wptr.lock();
    if (l == r) {          // 首先保证两个指针指向同一个vector对象，然后比较两个指针的位置即可
        return r && rp.curr > lp.curr;
    }
    return false;
}

bool operator>=(const StrBlobPtr &rp, const StrBlobPtr &lp)
{
    auto l = lp.wptr.lock();     
    auto r = rp.wptr.lock();
    if (l == r) {          // 首先保证两个指针指向同一个vector对象，然后比较两个指针的位置即可
        return r && rp.curr >= lp.curr;
    }
    return false;
} 

// 重载算数运算符，指针和指针不可进行算数运算，只能与整数进行加减运算
StrBlobPtr operator+(const StrBlobPtr &sp, int off)
{
    StrBlobPtr ret = sp;
    return ret += off;
}

StrBlobPtr operator-(const StrBlobPtr &sp, int off)
{
    StrBlobPtr ret = sp;
    return ret -= off;
}
#endif