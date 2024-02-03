# include <iostream>
int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    // 先打印出变量原来的值
    std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d
              << " e=" << e << " g=" << g << std::endl;

    a = 42;
    b = 42;
    c = 42;
    d = 42;
    e = 42;
    g = 42;
    // 打印变化后的变量值(因为报错，所以根本打印不出来)
    std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d
              << " e=" << e << " g=" << g << std::endl;
    return 0;
}