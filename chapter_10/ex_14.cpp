#include <iostream>

int main()
{
    auto f = [] (const int a, const int b) { return a + b; };
    int sum = f(10, 30);
    std::cout << "10 + 30 = " << sum << std::endl;
    return 0; 
}