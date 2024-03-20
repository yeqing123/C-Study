#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

// 将文件流map_file中读取的内容保存在一个map中
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key, value;
    // 先读取key，然后读取一行中其余的字符
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);    // 使用substr去掉开头的空格，然后向map中存入一个键值对
        } else {
            throw runtime_error("No rulle for " + key);
        }
    }
    return trans_map;
}

// 将word对照map中的规则进行转换，然后返回转换结果。如果map中没有对应的
// 规则，就返回word
string transform(string &word, map<string, string> trans_map)
{
    auto p = trans_map.find(word);
    if (p != trans_map.end()) {
        return p->second;    // 解引用迭代器，然后返回元素的second成员
    }
    return word;
}

// 将input文件中的内容按照map_fin文件中的规则转换格式后打印出来
void words_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);    // 构建map
    string text, word;
    while (getline(input, text)) {
        istringstream sin(text);
        bool firstword = true;       // 标记是否为一行中的第一个单词
        while (sin >> word) {
            if (firstword) {
                firstword = false;
            } else {                // 如果不是第一个单词，就在他的前面打印空格字符
                cout << " ";
            }
            cout << transform(word, trans_map);  // 输出转换后的字符串
        }
        cout << endl;
    }
}

int main()
{
    ifstream map_fin("map_file.txt"), input("input.txt"); // 创建两文件的输入流
    if (!map_fin || ! input) {                             
        cout << "Opening file failed!" << endl;
        return -1;
    }
    words_transform(map_fin, input);                    
    return 0;
}