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
    vector<string> wvec;
    string word;
    // 读入一组单词
    while (cin >> word) {
        // 将单词中的每个字母都改成大写形式
        for (auto &c : word) {
            c = toupper(c);
        }
        // 将修改后的词保存到vector对象中
        wvec.push_back(word);
    }
    // 打印结果，一个词占一行
    for (auto w : wvec) {
        cout << w << endl;
    }
    return 0;
}