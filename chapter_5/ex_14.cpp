#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string curr, pre, word;
    unsigned cnt = 1, repeatCnt = 0;
    // 连续输入若干个单词，统计连续出现最多的单词及其重复次数
    cout << "Please enter the words continuously:" << endl;
    // 先输入第一个单词
    if (cin >> pre) {
        while (cin >> curr) {
            if (curr == pre) {
                ++cnt;
            } else {
                if (cnt > repeatCnt) {
                    word = pre;
                    repeatCnt = cnt;
                    cnt = 1;   // 从1而不是0开始，记录重复次数
                }
                pre = curr;
            }
        }
        // 处理结尾处连续出现的单词
        if (cnt > repeatCnt) {
            word = curr;
            repeatCnt = cnt;
        }
        // 输出统计结果
        cout << "The word with the most consecutive occurrence is: " << word << '\n'
             << "Number of replication: " << repeatCnt << endl;
    }

}