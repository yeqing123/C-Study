#include <iostream>
#include <fstream>
#include <map>

using namespace std;

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
        // 改写练习3，使用insert函数实现单词计数
        auto res = count_words.insert({word, 1});   // insert返回一个pair对象
        if (!res.second) {         // 如果res的second为false，说明map中已经存在关键字为word的元素
            ++res.first->second;   // res的first成员是指向元素位置的迭代器，解引用该迭代器并将值加一
        }
    }
    // 遍历map中的每个元素，打印统计结果
    for (const pair<string, size_t> &cw : count_words) {
        cout << cw.first << " occurs " << cw.second 
             << (cw.second > 1 ? " times" : " time") << endl;
    }
    return 0;
}