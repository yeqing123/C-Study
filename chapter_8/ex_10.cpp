#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 打开文件并创建ifstream对象
    ifstream fin("iotest.txt");
    // 读取文件，以行为单位保存到一个string的vector中
    vector<string> lines;
    string s;
    while (getline(fin, s)) {
        lines.push_back(s);
    }
    // 使用istringstream对象读取vector中的每一个元素，每次读取一个单词
    for (auto s : lines) {
        // 每次循环都创建一个新的istringstream对象
        istringstream sin(s);
        string word;
        // 一次读取一个单词，并打印的控制台
        while (sin >> word) {
            cout << word << endl;
        }
    }
    return 0;
}