#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    do {
        string s1, s2;
        cout << "Please enter two strings:" << endl;
        if (cin >> s1 >> s2) {     // 多一个if判断，防止无任何输入的情况
            // 比较两个字符串的长度
            if (s1.size() < s2.size()) {
                cout << "The shorter string is: " << s1 << endl;
            }else if (s1.size() > s2.size()) {
                cout << "The shorter string is: " << s2 << endl;    
            } else {
                cout << "Two strings are of equal length." << endl;
            }
        }
    } while (cin);

    return 0;
}