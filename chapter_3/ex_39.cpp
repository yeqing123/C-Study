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
    string str1, str2;
    cout << "Enter two strings: " << endl;
    cin >> str1 >> str2;
    if (str1 > str2) {
        cout << "The s1 greater than s2." << endl;
    } else if (str1 < str2) {
        cout << "The s2 greater than s1." << endl;
    } else {
        cout << "The s1 equal s2." << endl;
    }

    // 比较两个C风格字符串内容，可以使用cstring头文件中strcmp函数
    char cstr1[80], cstr2[80];
    cout << "Enter two strings:" << endl;
    cin >> cstr1 >> cstr2;
    auto result = strcmp(cstr1, cstr2);
    switch(result) {
        case 1:
            cout << "The cs1 greater than cs2." << endl;
            break;
        case -1:
            cout << "The cs2 greater than cs1." << endl;
            break;
        case 0:
            cout << "The cs1 equal cs2." << endl;
            break;
        default:
            cout << "Undefined results" << endl;
            break;
    }
    
    return 0;
}