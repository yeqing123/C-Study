#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> text;
    string s;
    // 每次读取一行语句，如果直接输入回车将输入一个空串，表示段落的结束
    cout << "Enter a few lines of string, only enter a newline character\n" 
         << "in one line to indicate the end of the previous paragraph." << endl;
    while (getline(cin, s)) {
        text.push_back(s);
    }
    cout << "Change all characters in the first paragraph to uppercase letters:" << endl;
    // 使用迭代器遍历每个字符串，直至遇到空字符为止，表示第一段结束
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        // 将字符串全部修改为大写形式
        for (auto it2 = it -> begin(); it2 != it -> end(); ++it2) {
            *it2 = toupper(*it2);
        }
    }
    // 输出修改后的第一段文字
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }
    return 0;
}