#ifndef READSTRING_H
#define READSTRING_H
#include <iostream>

using namespace std;

class ReadString {
public:
    ReadString(istream &i = cin) : is(i) { }  // 默认从标准输入流读取
    string operator()()            // 重载函数调用运算符，从输入流中读取一行字符串
    {
        string line;
        if (!getline(is, line)) {  // 如果没有任何输入，则返回空串
            line = "";
        }
        return line;
    }
private:
    istream &is;
};
#endif