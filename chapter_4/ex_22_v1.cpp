#include <iostream>

using namespace std;

// 版本一：只使用条件运算符，虽然书写的代码较少，但是当多层条件表达式嵌套后，使代码变得难以理解和阅读
int main()
{
    double grade;
    string finalgrade,                                  // 保存成绩档次
           error1_tip = "Can't be greater than 100",   // 当分数大于100时的错误信息
           error2_tip = "Can't be less than 0",        // 当分数小于0时的错误信息
           right_tip = "The level of this score is: ", // 当分数有效时的正确信息
           enter_tip = "Please enter the score that you want to check:(press Ctr+Z to end)"; // 提示用户输入的信息

    cout << enter_tip << endl;
    while (cin >> grade) {
        // 检查成绩档次
        finalgrade = (grade > 90) ? "high pass" : 
                     (grade > 75) ? "pass" : 
                     (grade >= 60) ? "low pass" : "fail";
        // 当成绩无效时（大于100或小于0）输出错误提示，否则输出成绩的档次
        cout << ((grade > 100) ? error1_tip : ((grade < 0) ? error2_tip : right_tip + finalgrade)) << endl;
        cout << enter_tip << endl;
    }
    return 0;
}