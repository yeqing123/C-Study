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
    cout << "Please enter a set of words (press Ctr+Z to end):" << endl;
    while (cin >> word) {
        // 将词保存到vector对象中
        wvec.push_back(word);
    }
    for (auto word : wvec) {
        // 将单词中的每个字母都改成大写形式
        for (auto &c : word) {
            c = toupper(c);
        }
        // 打印修改后单词，一个词占一行
        cout << word << endl;
    }
    return 0;
}