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
    HasPtr &operator=(const HasPtr&);
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

int main()
{
    int n;
    while (true) {
        vector<HasPtr> *vp = new vector<HasPtr>;     // 在动态内存中创建vector对象
        cout << "Please enter the size of the vector: ";
        if (!(cin >> n) || n <= 0) {                 // 当结束输入或输入的值小于等于零时，结束循环
            break;
        }
        for (int i = n; i > 0; --i) {
            vp->push_back(HasPtr(to_string(i)));
        }
        print_vector(vp);
        cout << endl;

        // 对hsvec执行sort，对其进行排序
        /*
        * 经测试，在我使用的gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0上，
        * 当元素个数不超过16时，编译器采用的时插入排序法，不会调用swap函数。
        * 当数量超过16时，采用快速排序法，会调用swap函数，但不总是调用该函数，
        * 当剩余未排序元素个数小于17时，又会采用插入排序法。这应该是优化性能的一种选择。
        */
        sort(vp->begin(), vp->end());
        cout << "Sort all elements:" << endl;
        print_vector(vp);
        cout << endl;
        delete vp;                                 // 每次循环结束时，释放vector对象的内存
    }
}