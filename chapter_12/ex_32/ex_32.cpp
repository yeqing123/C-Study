#include <iostream>
#include <fstream>
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
    // 从ifstream中读取文件内容，并建立查询map
    TextQuery tq(infile);
    // 与用户交互，提示用户输入要查询的单词，完成查询并打印结果
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        // 若遇到文件结束或用户输入了'q'，则终止循环
        if (!(cin >> s) || s == "q") {
            break;
        }
        // 查询并打印结果
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream infile("../input_file.txt");
    if (!infile) {
        cout << "File open failed!" << endl;
        return -1;
    }
    runQueries(infile);
    return 0;
}