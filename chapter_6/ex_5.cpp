#include <iostream>
using namespace std;
// absolute函数返回实参的绝对值
double absolute(double val)
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
         // 调用absolute函数，返回val的绝对值
        cout << absolute(val) << endl;
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