#include <iostream>
int main() 
{
    int sum = 0, val = 50;
    // 只要val小于等于100，while循环就会执行
    while(val <= 100){
        sum += val;
        ++val;
    }
    std::cout << "The sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}