#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 提示输入两个字符串，并输出较短的一个
    do {
        string s1, s2;
        cout << "Please enter two strings:" << endl;
        if (cin >> s1 >> s2) {
            // 如果两个字符串长度不相等，则输出较短的一个
            if (s1.size() != s2.size()) {
                cout << "The shorter string is: ";
                if (s1.size() < s2.size()) {
                    cout << s1 << endl;
                }else if (s1.size() > s2.size()) {
                    cout << s2 << endl;
                }
            } else {
                cout << "Two strings are of equal length." << endl;
            }
        }
    } while (cin);

    return 0;
}