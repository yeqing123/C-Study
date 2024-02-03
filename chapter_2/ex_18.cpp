# include <iostream>
int main()
{
    int val = 10, *p = &val;
    std::cout << val << " " << *p << std::endl;

    int v = 20;
    // 修改指针p的值
    p = &v;
    // 修改指针所指对象的值
    *p = 30;
    std::cout << v << " " << *p << std::endl;
    return 0;
}