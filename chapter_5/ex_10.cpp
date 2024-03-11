#include <iostream>

using namespace std;

string make_plural(unsigned count, const string &word, const string &s)
{
    return count > 1 ? word + s : word;
}

int main()
{
    // 从输入的文本中统计多少元音字母，也可以使用switch语句
    unsigned vowelCnt = 0;
    char ch;
    cout << "Please enter a piece of text:" << endl;
    while (cin >> ch) {
        switch(ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                ++vowelCnt;
        }
        
    }
    cout << "There " << (vowelCnt > 1 ? "are " : "is ") << vowelCnt << " "
         << make_plural(vowelCnt, "vowel", "s") << " in the text you entered." << endl;
    return 0;
}