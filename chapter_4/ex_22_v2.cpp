#include <iostream>

using namespace std;

// 版本二：使用if...else，程序更直观更容易理解
int main()
{
    double grade;
    string error1_tip = "Can't be greater than 100",   // 当分数大于100时的错误信息
           error2_tip = "Can't be less than 0",        // 当分数小于0时的错误信息
           right_tip = "The level of this score is: ", // 当分数有效时的正确信息
           enter_tip = "Please enter the score that you want to check:(press Ctr+Z to end)"; // 提示用户输入的信息
    
    cout << enter_tip << endl;
    while (cin >> grade) {
        if (grade > 100) {
            cout << error1_tip << endl;
        } else if (grade > 90) {
            cout << right_tip + "high pass" << endl;
        } else if (grade > 75) {
            cout << right_tip + "pass" << endl;
        } else if (grade >= 60) {     // 按照惯例，我们不满60分的成绩确定为不及格
            cout << right_tip + "low pass" << endl;
        } else if (grade >= 0) {
            cout << right_tip + "fail" << endl;
        } else {
            cout << error2_tip << endl;
        }
        cout << enter_tip << endl;
    }
    return 0;
}