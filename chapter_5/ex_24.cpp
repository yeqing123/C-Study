#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::runtime_error;
int main()
{
    // 从标准输入中读取两个整数，并计算第一个数除以第二个数的结果
    int i1, i2;
    do {
        cout << "Please enter two integers: " << endl;
        cin >> i1 >> i2;       // 输入两个整数
        if (i2 == 0) {         // 除数不能为0
            throw runtime_error("The divisor can't be zero!");  // 当出现除数为0时抛出一个runtime_error异常
        }
        cout << i1 << " divide by " << i2 << " equals "  // 输出第一个整数除以第二个整数的结果
            << i1 / i2 << endl;
    } while (cin);
    
    return 0;
}