#include <iostream>
#include <string>
#include <cstring> // C语言的头文件string.h的C++版本
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 比较两个string对象
    string s1("some string"), s2("same string");
    if (s1 > s2) {
        cout << "The s1 greater than s2." << endl;
    } else if (s1 < s2) {
        cout << "The s2 greater than s1." << endl;
    } else {
        cout << "The s1 equal s2." << endl;
    }

    // 比较两个C风格字符串内容
    char cs1[] = "some string", cs2[] = "same string";
    if (strcmp(cs1, cs2) > 0) {
        cout << "The cs1 greater than cs2." << endl;
    } else if (strcmp(cs1, cs2) < 0) {
        cout << "The cs2 greater than cs1." << endl;
    } else {
        cout << "The cs1 equal cs2." << endl;
    }
    
    return 0;
}