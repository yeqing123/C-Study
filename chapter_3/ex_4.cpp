#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // 比较两个字符串是否相等，如果不相等，则比较其大小，并打印较大的一个
    if (s1 != s2) {
        cout << "The larger string is: ";
        // 比较两个字符串的大小，打印较大的一个
        if (s1 > s2) {
            cout << s1 << endl;
        } else {
            cout << s2 << endl;
        }
    }
    // 比较两个字符串的长度是否相等，如果不相等，则比较其长度，打印较长的一个
    if (s1.size() != s2.size()) {
        cout << "The longer length string is: ";
        // 比较两个字符串的长短，打印较长的一个
        if (s1.size() > s2.size()) {
            cout << s1 << endl;
        } else {
            cout << s2 << endl;
        }
    }
    return 0;
}