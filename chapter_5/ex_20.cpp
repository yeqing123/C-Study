#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string s1, s2;
    cout << "Please enter words continuously:" << endl;
    // 先输入第一个单词
    if (cin >> s1) {
        // 连续输入单词，并判断是否存在一个单词连续出现两次的情况
        while (cin >> s2) {
            if (s1 == s2) {
                cout << "Word '" << s1 << "' appears repeatedly." << endl;
                break;    // 结束while循环
            } else { 
                s1 = s2;
            }
        }
        if (!cin) {  // 当输入流结束时，说明没有出现单词连续重复的情况
            cout << "No words are repeated consecutively!" << endl;
        }
    }
    return 0;
}