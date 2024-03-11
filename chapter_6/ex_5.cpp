#include <iostream>
using namespace std;
// 使用if...else返回实参的绝对值，
// 也可以使用头文件cmatch中的abs库函数获取绝对值
double myAbs(double val)
{
    if (val < 0) {
        return val * -1;
    } else {
        return val;
    }
}

int main()
{
    double val;
    cout << "Enter a digit and I will return its absolute value." << endl;
    while (cin >> val) {
         // 调用abs函数，返回val的绝对值
        cout << myAbs(val) << endl;
        cout << "Ary Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c =='n') {
            break;
        }
        cout << "Enter a digit: " << endl;
    }
    return 0;
}