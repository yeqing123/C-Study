#include <iostream>
using namespace std;
// 定义函数，计算参数val的阶乘，并返回结果
long long fact(int val)
{
    long long result = 1;   // 保存计算结果
    while (val > 1) {
        result *= val--;
    }
    return result;
}

int main() {
 
    int val;
    cout << "Enter a integer: ";
    // 由用户输入一个数字，我们将函数fact的返回类型改为long long，以免数值过大无法存放
    while (cin >> val) {
        cout << val << "! is: " << fact(val) << endl;
        cout << "Do you continue? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c == 'n') {
            break;
        }
        cout << "Enter a integer: ";
    }
    return 0;
}