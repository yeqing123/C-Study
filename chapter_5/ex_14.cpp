#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 定义三个string对象，分别保存当前单词、上一个单词和重复次数最多的单词
    string currWord, preWord = "\0", mostWord;
    unsigned cnt = 1, maxCnt = 0;
    cout << "Please enter some words:" << endl;
    while (cin >> currWord) {
        if (currWord == preWord) {
            ++cnt;
        } else {
            if (cnt > maxCnt) {      // 如果出现的次数大于记录的次数，则更新记录
                maxCnt = cnt;
                mostWord = preWord;
            }
            cnt = 1;
            preWord = currWord;
        }
    }
    // 输出统计结果
    if (maxCnt > 1) {
        cout << "The word with the most consecutive occurrence is: " << mostWord << '\n'
            << "It appeared " << maxCnt << " times" << endl;
    } else {
        cout << "No repeated words! Each word appears only once." << endl;
    }
    return 0;
}