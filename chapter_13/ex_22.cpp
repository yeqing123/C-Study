#include <iostream>
#include <string>
#include <cstring>

class HasPtr {
friend std::ostream &print(std::ostream&, const HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) 
    { 
        std::cout << "constructor: HasPtr(const std::string&)" << std::endl;
    }
    // 添加拷贝构造函数
    HasPtr(const HasPtr &hp) : 
        ps(new std::string(*hp.ps)), i(hp.i)    // 拷贝指针ps指向的对象，而不是拷贝指针本身
    { 
        std::cout << "copy constructor: HasPtr(const HasPtr&)" << std::endl;
    }   
    // 添加赋值运算符，注意表达式执行顺序，以保证一个对象赋值给它自身时也正确
    inline HasPtr &operator=(const HasPtr &rhp) 
    {
        std::cout << "assignment operator" << std::endl;
        std::string *newp = new std::string(*rhp.ps);   // 拷贝指针指向对象
        delete ps;                                      // 销毁原string对象
        ps = newp;                                      // 指向新string对象
        i = rhp.i;
        return *this;
    }
    // 添加析构函数
    ~HasPtr() 
    { 
        delete ps;                                 // 释放ps所占内存
        std::cout << "~HasPtr()" << std::endl;
    }                      
private:
    std::string *ps;
    int i;
};

// 验证赋值运算符是否正确
std::ostream &print(std::ostream &os, const HasPtr &hp)
{
    os << *hp.ps;    
    return os;
}

int main()
{
    HasPtr hp("hello");
    hp = hp;                            // 拷贝自身，以验证赋值运算符可以正常工作
    print(std::cout, hp) << std::endl;
    std::cout << std::endl;

    HasPtr hp2 = hp;                    // 调用赋值运算符
    print(std::cout, hp2) << std::endl;
    return 0;
}