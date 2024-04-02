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

    // 测试使用智能指针的优势：只要对map和vector成员的引用计数不为0，
    // 就不会释放TextQuery的内存
    ifstream infile2("../input_file.txt");
    QueryResult qr;
    {
        TextQuery tq(infile2);
        qr = tq.query("is");
    }    // 如果使用普通指针，那么到这里tq就会被释放
    print(cout, qr) << endl;

    return 0;
}