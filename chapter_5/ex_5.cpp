#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
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
            // 确定十位数等级
            if (tens_digit == 9) {
                level = "A";
            } else if (tens_digit == 8) {
                level = "B";
            } else if (tens_digit == 7) {
                level = "C";
            } else {
                level = "D";
            }
            // 确定个位数等级
            if (single_digit < 3) {
                level += "-";
            } else if (single_digit > 7) {
                level += "+";
            }
        }
        // 输出考试等级
        cout << "Examination level is: " << level << endl;
    }
    return 0;
}