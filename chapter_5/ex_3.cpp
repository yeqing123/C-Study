#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;  // 使用逗号运算符，代替原来的语句块
    
    std::cout << "Sum of 1 to 10 inclusive is " 
              << sum << std::endl;
    return 0;
}