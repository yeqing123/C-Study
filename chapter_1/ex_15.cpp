# include <iostream>
int main()
{
    // 语法错误
    std::cout << Enter two number << std::endl;
    std::cout << "Enter two numbers" << std::endl

    // 类型错误
    int v = "Hello";
    std::cout << v << std::endl;

    // 声明错误
    cout << "Enter two numbers" << endl;
    int v1 = 10;
    std::cout << v << std::endl;

    return 0;
}