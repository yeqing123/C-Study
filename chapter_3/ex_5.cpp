#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str1, str2;
    // 先输入第一个字符串
    if (cin >> str1) {
        // 连续输入多个字符串，并将它们连接成一个大字符串
        while (cin >> str2) {
            // 将两个字符串相加，就是将它们连接在一起，并有空格把它们分隔开
            str1 += " " + str2;
        }
        // 输出大字符串
        cout << str1 << endl;
    }
    return 0;
}