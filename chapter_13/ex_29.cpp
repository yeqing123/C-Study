#include <iostream>
#include <string>

using namespace std;

// 为HasPtr添加引用计数器，使变成行为向指针的类
class HasPtr {
// 声明友元函数
friend void swap(HasPtr&, HasPtr&);   
friend ostream &print(ostream&, const HasPtr&);  
public:
    HasPtr(const string&);
    HasPtr(const HasPtr&);
    HasPtr &operator=(const HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *user;                            // 记录有多少个对象共享*ps成员
};

HasPtr::HasPtr(const string &s = string())
{ 
    ps = new string(s);
    user = new size_t(1);                    // 创建新的引用计数，并初始化为1
    i = 0;
}

// 添加拷贝构造函数，并将引用计数递增
HasPtr::HasPtr(const HasPtr &hp)
{ 
    ps = hp.ps;
    i = hp.i;
    user = hp.user;
    ++*user;                                 // 递增引用计数
}   

// 添加赋值运算符，同样要保证自赋值的正确性
inline HasPtr &HasPtr::operator=(const HasPtr &rhp) 
{
    // 先递增后递减，保证自赋值的正确
    ++*rhp.user;
    if (--*user == 0) {    // 如果运算符左侧的对象引用计数为0，则释放其内存
        delete ps;
        delete user;
    }
    ps = rhp.ps;
    user = rhp.user;
    i = rhp.i;
    return *this;
}
// 添加析构函数
HasPtr::~HasPtr() 
{ 
    if (--*user == 0) {          // 递减引用计数，表示少了一个共享string成员的对象，
        delete ps;               // 如果引用计数为0，则释放其内存
        delete user;
    }
} 

ostream &print(ostream &os, const HasPtr &hp)
{
    os << *hp.ps << "\treference count: " << *hp.user;;    
    return os;
}

// 自定义swap函数
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);    // 使用标准库的swap函数交换指针ps
    swap(lhs.i, rhs.i);      // 使用标准库的swap函数交换i
    cout << "Two HasPtr objects were swapped" << endl;  
}

int main()
{
    HasPtr hs("hello"), hs2("world");
    print(cout, hs) << endl;
    print(cout, hs2) << endl;
    cout << endl;

    swap(hs, hs2);         // 调用自定义swap
    print(cout, hs) << endl;
    print(cout, hs2) << endl;
    return 0;
}