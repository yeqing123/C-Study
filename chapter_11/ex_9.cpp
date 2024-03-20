#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// 删除单词两端的标点，并将大写字母变为小写字母
void trans(string &word)
{
    for (int p = 0; p < word.size(); ++p) {
        // 只删除单词两端的标点符号，中间的不删除
        if ((p == word.size() - 1 || p == 0) && ispunct(word[p])) {
            word.erase(p, 1);
        } else if (word[p] >= 'A' && word[p] <= 'Z') {
            word[p] -= 'A';         // 先计算出该大写字母到字母A的距离
            word[p] += 'a';         // 然后再由字母a加上该距离，就是对应的小写字母
        }
    }
}

int main()
{
    map<string, list<int>> line_numbers;
    ifstream in("words.txt");
    if (!in) {
        cerr << "Opening file fail!" << endl;
        exit(1);
    }
    string str, word;
    int ln = 0;         // 保存行号
    // 逐行读取文件内容
    while (getline(in, str)) {
        ++ln;
        istringstream sin(str);
        while (sin >> word) {       // 从每行中读取单词，并保存其所在行号
            trans(word);
            line_numbers[word].push_back(ln);
        }
    }
    // 输出结果
    for (auto element : line_numbers) {
        cout << "The line of " << element.first << ": ";
        for (auto number : element.second) {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}