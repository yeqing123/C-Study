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
        ++count_words[word];       // 将与word对应的值加一，如果不存在就新创建一个元素
    }
    // 遍历map中的每个元素，打印统计结果
    for (const pair<string, size_t> &cw : count_words) {
        cout << cw.first << " occurs " << cw.second 
             << (cw.second > 1 ? " times" : " time") << endl;
    }
    return 0;
}