#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// 使用条件运算符改写上一题
int main()
{
    unsigned score;  // 定义一个保存成绩的变量
    string level;   // 与成绩对应的等级
    cout << "Please enter your score(press Ctr+Z to end):" << endl;
    while (cin >> score) {
        if (score < 0 || score > 100) {                 // 输入的成绩无效
            cout << "The score is invalid!" << endl;
            continue;
        } else if (score == 100) {
            level = "A++";
        } else if (score < 60) {                        // 60分以下为不及格
            level = "F";
        } else {
            int tens_digit = score / 10;   // 成绩的十位数
            int single_digit = score % 10; // 成绩的个位数
            // 确定十位数的等记（注意条件表达式满足右结合律）
            level = tens_digit == 9 ? "A" : tens_digit == 8 ? "B" : tens_digit == 7 ? "C" : "D";
            // 确定个位数的等级
            level += single_digit < 3 ? "-" : single_digit > 7 ? "+" : "";
        }
        // 输出考试等级
        cout << "Examination level is: " << level << endl;
    }
    return 0;
}