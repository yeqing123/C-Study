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
    cout << "Please enter two integers: " << endl;
    while (cin >> i1 >> i2) {       // 输入两个整数
        try {
            if (i2 == 0) {         // 除数不能为0
                throw runtime_error("The divisor can't be zero!");  // 当出现除数为0时抛出一个runtime_error异常
            }
            cout << i1 << " divide by " << i2 << " equals "  // 输出第一个整数除以第二个整数的结果
                << i1 / i2 << endl;
        } catch (runtime_error err) {    // 捕获并处理异常
            cout << err.what() << endl;  // 输出错误信息
            cout << "Whether to re-enter?(y or n): ";
            char c;
            cin >> c;
            if (c != 'y' && c != 'Y') {
                break;
            }
        }
    }
    
    return 0;
}