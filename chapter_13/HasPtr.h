/*
* 之前几个直接定义在源文件中的HasPtr类的版本都是不完整的，
* 现在定义一个完整版本的HasPtr类，并单独放在一个头文件中，
* 从练习53开始，此后所有的源文件都使用该头文件中的HasPtr。
*/
#ifndef MY_HASPTR_H
#define MY_HASPTR_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 为HasPtr添加引用计数器，使变成行为向指针的类
class HasPtr {
// 声明友元函数
friend void swap(HasPtr&, HasPtr&);   
friend ostream &print(ostream&, const HasPtr&);  
public:
    HasPtr(const string&);
    HasPtr(const HasPtr&);
    // HasPtr &operator=(HasPtr);     // 使用自定义swap函数，即可以执行拷贝赋值，也可以进行移动赋值
    HasPtr &operator=(HasPtr &&rhp) noexcept;  // 重载赋值运算符
    bool operator<(const HasPtr&);
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
    cout << "Copy construct: ";
    print(cout, hp) << endl;
    ps = hp.ps;
    i = hp.i;
    user = hp.user;
    ++*user;                                 // 递增引用计数
}   

// // 添加赋值运算符，同样要保证自赋值的正确性
// inline HasPtr &HasPtr::operator=(const HasPtr &rhp) 
// {
//     // 先递增后递减，保证自赋值的正确
//     ++*rhp.user;
//     if (--*user == 0) {    // 如果运算符左侧的对象引用计数为0，则释放其内存
//         delete ps;
//         delete user;
//     }
//     ps = rhp.ps;
//     user = rhp.user;
//     i = rhp.i;
//     return *this;
// }

// 交换版本的拷贝赋值运算符，它也可以进行移动赋值
// inline HasPtr &HasPtr::operator=(HasPtr rhp) 
// {
//     cout << "Assignment operation for the swap version" << endl;
//     swap(*this, rhp);    // 使用自定义的swap函数
//     return *this;
// }

// 重载赋值运算符，只进行移动赋值操作
inline HasPtr &HasPtr::operator=(HasPtr &&rhp) noexcept
{
    cout << "Move the assignment operation" << endl;
    if (this != &rhp) {   // 检测是否为自赋值
        if (--*user == 0) {  // 引用计数减一，若引用计数为0，则释放无用的内存          
            delete ps;               
            delete user;
        }
        // 拷贝数据成员前，先递增引用计数user。此后在rhp运行析构时会再次递减其引用计数。
        // 如此一增一减正好与赋值运算的逻辑相吻合。
        ++*rhp.user;      
        ps = rhp.ps;
        user = rhp.user;   
        i = rhp.i;
        // 因为HasPtr的析构函数中有条件判断，所以在rhp运行析构函数是安全的
    }
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
    os << *hp.ps << " ";    
    return os;
}

// 自定义swap函数
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);    // 使用标准库的swap函数交换指针ps
    swap(lhs.i, rhs.i);      // 使用标准库的swap函数交换i
    cout << "Swap " << *lhs.ps << " and " << *rhs.ps << endl;  
}

// 自定义<运算符
inline bool HasPtr::operator<(const HasPtr &rhs)
{
    return *ps < *rhs.ps;
}


void print_vector(const vector<HasPtr> *vp)
{
    for (int i = 0; i < vp->size(); ++i) {
        if (i < vp->size() - 1) {
            print(cout, vp->at(i));
        } else {
            print(cout, vp->at(i)) << endl;;
        }
    }
}
#endif