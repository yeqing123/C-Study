#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    // 一次输入一整行
    string line;
    // 从标准输入读入一整行
    getline(cin, line);
    // 打印输入的数据
    cout << line << endl;

    // 一次输入一个单词
    string word;
    while (cin >> word) {
        cout << word << endl;  // 每输出一个单词会在后面多加一个换行符
    }
    return 0;
}