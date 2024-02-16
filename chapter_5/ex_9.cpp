#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    // 从输入的文本中统计多少元音字母
    unsigned vowelCnt = 0;
    char ch;
    cout << "Please enter a piece of text:" << endl;
    while (cin >> ch) {
        // 转换成小写形式
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || 
            ch == 'i' || ch == 'o' || 
            ch == 'u') {
            // 变量加1
            ++vowelCnt;
        }
    }
    cout << "The number of vowels is: " << vowelCnt << endl;
    return 0;
}