#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

// 使用无序容器map重写ex_33的单词转换程序。整个程序几乎与原来的一样，只是将map变成了unordered_map而已。

unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() == 1) {      // 如果key后面只有一个空格，则抛出异常
            throw runtime_error("No rule for " + key);
        }
        trans_map[key] = value.substr(1);  // 跳过开头的一个空格，将字符串存入map
    }
    return trans_map;
}

string transform(string &word, unordered_map<string, string> &map)
{
    auto p = map.find(word);    // 查找是否有对应的转换规则
    if (p != map.end()) {
        return p->second;       // 如果有就返回规则对应的字符串
    }
    return word;                // 如果没有，就直接返回word
}

void words_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);  // 读取规则文件，然后创建map对象
    string text, word;
    while (getline(input, text)) {        // 读取文本文件，一次一行
        istringstream sin(text);
        bool first_word = true;           // 标识是否为一行中的第一个单词
        while (sin >> word) {
            if (first_word) {
                first_word = false;
            } else {
                cout << " ";              // 如果不是第一个单词，打印一个空格
            } 
            cout << transform(word, trans_map); // 打印转换后的单词
        }
        cout << endl;
    }
}

int main()
{
    // 还是继续使用ex_33中的两个文件，map_file.txt 是规则文件，input_txt是文本文件
    ifstream mf_in("ex_33/map_file.txt"), input("ex_33/input.txt");
    if (!mf_in || !input) {
        cout << "Opening file failed!" << endl;
        return -1;
    }
    words_transform(mf_in, input);
    return 0;
}