#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

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
    ifstream in("words.txt");
    if (!in) {
        cout << "Opening file fail!" << endl;
        exit(1);
    }
    map<string, size_t> count_words;
    string word;
    while (in >> word) {
        trans(word);               // 去掉单词两端的标点，并将大写字母转换成小写字母
        ++count_words[word];       // 单词数量加1，如果还没有改单词则创建新的键值对
    }
    // 打印统计结果
    for (const pair<string, size_t> &cw : count_words) {
        cout << cw.first << " occurs " << cw.second 
             << (cw.second > 1 ? " times" : " time") << endl;
    }
    return 0;
}