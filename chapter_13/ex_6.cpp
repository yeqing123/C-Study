#include <iostream>
#include <string>
#include <cstring>

class HasPtr {
friend std::ostream &print(std::ostream&, const HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) 
    { 
        std::cout << "HasPtr(const std::string&)" << std::endl;
    }
    // 添加拷贝构造函数
    HasPtr(const HasPtr &hp) : 
        ps(new std::string(*hp.ps)), i(hp.i)    // 拷贝指针ps指向的对象，而不是拷贝指针本身
    { 
        std::cout << "HasPtr(const HasPtr&)" << std::endl;
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
private:
    std::string *ps;
    int i;
};

// 验证赋值运算符是否正确
std::ostream &print(std::ostream &os, const HasPtr &hp)
{
    int j = hp.i;
    const char *cstr = hp.ps->c_str();  // 将指针指向的string对象，转换成C风格的字符串
    while (cstr[j]) {                   // 当遇到末尾的'\0'字符时，退出循环
        os << cstr[j++];
    }
    return os;
}

int main()
{
    HasPtr hp("hello");
    print(std::cout, hp) << std::endl;

    HasPtr hp2 = hp;                    // 程序意图使用自定义的赋值运算符，但是编译器使用了拷贝构造函数
    print(std::cout, hp2) << std::endl;
    return 0;
}