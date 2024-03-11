#include <iostream>
#include <typeinfo>
int main()
{
    const int i = 42;
    auto j = i;   //i是int类型，但是i的顶层const会被忽略
    const auto &k = i;  //k是const int类型的引用(即一个绑定到整数类型的常量引用)
    auto *p = &i;    //p是一个指向整型常量的指针
    const auto j2 = i, &k2 = i; // j2是一个整型常量（const int）；k2是一个常量引用，它保定整型变量i

    // 验证推断的类型是否正确
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
    
    return 0;
}