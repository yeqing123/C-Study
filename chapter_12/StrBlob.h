#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlobPtr;   // 提前声明StrBlobPtr类
class StrBlob {
// 声明友元类
friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> li);
    bool empty();
    size_type size();
    // 访问元素
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    // 删除和添加元素
    void push_back(const string&);
    void pop_back();
    // 返回指向首个元素的StrBlobPtr对象
    StrBlobPtr begin() const;
    // 返回指向末尾元素下一位的StrBlobPtr对象
    StrBlobPtr end() const;
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

inline StrBlob::size_type StrBlob::size() {
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

inline void StrBlob::pop_back() {
    data->pop_back();
}



// 实现一个指针类，它可以绑定一个StrBlob对象，指向其所绑定对象中的某个元素，并防止用户访问不存在的元素。
// 它与绑定的StrBlob对象之间是数据的“弱”共享关系，即绑定一个对象并不会增加shared_ptr指针引用计数的递增，也不影响内存的释放。
class StrBlobPtr {
// 声明友元函数
friend bool eq(const StrBlobPtr&, const StrBlobPtr&);  // 判断两个StrBlobPtr是否相等
friend bool neq(const StrBlobPtr&, const StrBlobPtr&); // 判断两个StrBlobPtr是否不相等
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &sb, size_t index = 0) : wptr(sb.data), curr(index) {}
    string &deref();     // 解引用
    StrBlobPtr &incr();       // 当前位置递增一位
    StrBlobPtr &incr(int);    // 当前位置递增指定数量
    StrBlobPtr &decr();       // 当前位置递减一位
    StrBlobPtr &decr(int);    // 当前位置递减指定数量
private:
    size_t curr;              // 指向元素的当前位置
    weak_ptr<vector<string>> wptr;
    // 检查当前位置是否合法
    shared_ptr<vector<string>> check(size_t, const string&);
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

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t curr, const string &msg)
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
    check(curr + off, "increment past end of StrBlobPtr");
    curr += off;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr()
{
    check(curr, "decrement past end of StrBlobPtr");
    --curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr(int off)
{
    check(curr - off, "decrement past end of StrBlobPtr");
    curr -= off;
    return *this;
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
#endif