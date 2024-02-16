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
    cout << "Please enter your mark:";
    while (cin >> mark) {
        // 使用条件运算符改写上一题
        level = mark >= 0 && mark < 60 ? "E" : 
                    (mark >= 60 && mark < 70 ? "D" : 
                        (mark >= 70 && mark < 80 ? "C": 
                            (mark >= 80 && mark < 90 ? "B" :
                                (mark >= 90 && mark < 100 ? "A":
                                    (mark >= 100 ? "A+": "")
                                )
                            )
                        )
                    );
        // 输出考试等级
        cout << "Examination level is: " << level << endl;
        cout << "Please enter your mark:";  // 连续输入时需要再次输出提示
    }
    return 0;
}