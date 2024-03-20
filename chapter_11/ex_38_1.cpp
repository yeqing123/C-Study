#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

// 使用无序容器map重写单词统计程序，没有啥区别，就是将原来的map换成unordered_map而已！

void words_count(ifstream &in)
{
    string word;
    unordered_map<string, size_t> wc_map;
    while (in >> word) {
        ++wc_map[word];
    }
    for (auto wc : wc_map) {
        cout << wc.first << " occurs " 
             << wc.second << (wc.second > 1 ? " times" : " time") << endl;
    }
}

int main()
{
    ifstream fin("words.txt");
    if (!fin) {
        cout << "Opening file failed!" << endl;
        return -1;
    }
    words_count(fin);
    return 0;
}