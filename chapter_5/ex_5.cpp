#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    unsigned mark;  // 定义一个保存成绩的变量
    string level;   // 与成绩对应的等级
    cout << "Please enter your mark:" << endl;
    while (cin >> mark) {
        if (mark < 60) {
            level = "E";
        } else if (mark >= 60 && mark < 70) {
            level = "D";
        } else if (mark >= 70 && mark < 80) {
            level = "C";
        } else if (mark >= 80 && mark < 90) {
            level = "B";
        } else if (mark >= 90 && mark < 100) {
            level = "A";
        } else if (mark == 100) {
            level ="A+";
        }
        // 输出考试等级
        cout << "Examination level is: " << level << endl;
        cout << "Please enter your mark:" << endl;  // 连续输入时需要再次输出提示
    }
    return 0;
}