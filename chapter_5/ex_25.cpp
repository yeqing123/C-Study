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
    // 输入两个整数
    while (cin >> i1 >> i2) {
        try {
            if (i2 == 0) {  // 被除数是0，则抛出runtime_error异常
                throw runtime_error("Zero cannot used as the dividend!");
            }
            // 如果能执行到这一步，说明没有抛出异常。程序可以正常运行
            cout << i1 << " / " << i2 << " = "  // 输出第一个整数除以第二个整数的结果
                << i1 / i2 << endl;
        } catch (runtime_error err) {  // 捕获runtime_error异常，并作出处理
            cout << err.what() << "\nTry Again? Enter 'y' or 'n'" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
        cout << "Please enter two integers: " << endl;
    }
    
    return 0;
}