# include <iostream>
int main()
{
    int i = 10, j = 20, *p = &i;
    std::cout << p << " " << *p << std::endl;
    // 修改指针p的值
    p = &j;
    std::cout << p << " " << *p << std::endl;
    // 修改指针所指对象的值
    *p = 30;
    std::cout << p << " " << *p << std::endl;
    j = 40;
    std::cout << p << " " << *p << std::endl;
    return 0;
}