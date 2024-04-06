#include <iostream>
#include <string>

using namespace std;

// 为HasPtr添加引用计数器，使变成行为向指针的类
class HasPtr {
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
// 验证赋值运算符是否正确
ostream &print(ostream &os, const HasPtr &hp)
{
    os << *hp.ps << "\nreference count: " << *hp.user;;    
    return os;
}

int main()
{
    HasPtr hp("hello");
    hp = hp;                            // 拷贝自身，以验证赋值运算符可以正常工作
    print(cout, hp) << endl;            // 共享hello的只有hp一个对象，所以引用计数为1
    cout << endl;

    HasPtr hp2("world"), hp3(hp2);      // 共享world的有两个对象，所以它的引用计数为2
    print(cout, hp2) << endl;           
    cout << endl;

    hp3 = hp;                           // 共享world的对象少一个，其引用计数减一，变为1          
    print(cout, hp) << endl;            // 共享hello的对象多一个，其引用计数加一，变为2
    print(cout, hp2) << endl;
    cout << endl;

    HasPtr *p = new HasPtr("Hiya!");
    hp3 = *p;
    delete p;                          // 因为我们使HasPtr的行为像指针，所以delete p 只是释放了
    print(cout, hp3) << endl;          // *p对象中为指针成员ps和user分配的内存，并没有释放它们所指对象的内存，
    // print(cout, *p) << endl;           // 因此虽然执行*p会报错，但是使用hp3依然可以打印字符串Hiya!
    return 0;
}