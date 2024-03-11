#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    // 从输入的文本中分别统计多少元音字母、空格、制表符和换行符
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,  // 元音字母个数
             spaceCnt = 0, tabCnt = 0, newlineCnt = 0;            // 空格符、制表符、换行符的个数
    char ch;
    cout << "Please enter a piece of text:" << endl;
    // cin.get()函数可以接受空格、制表符和回车，并且读入到变量ch中，然后返回输入流，直至遇到结束符为止。
    // 反之，原来的cin >> ch语句，则不会将空格、制表符和回车读入到变量中，因此无法进行统计。
    while (cin.get(ch)) {  
        switch(ch) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
        }
    }
    cout << "Number of vowel 'a': " << aCnt << endl;
    cout << "Number of vowel 'e': " << eCnt << endl;
    cout << "Number of vowel 'i': " << iCnt << endl;
    cout << "Number of vowel 'o': " << oCnt << endl;
    cout << "Number of vowel 'u': " << uCnt << endl;
    cout << "Number of space: " << spaceCnt << endl;
    cout << "Number of tab: " << tabCnt << endl;
    cout << "Number of : newline: " << newlineCnt << endl;
    return 0;
}