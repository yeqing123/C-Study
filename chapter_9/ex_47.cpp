#include <iostream>
#include <string>
using namespace std;
// 定义包含字母和数字字符串的全局变量
string letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
string numbers("0123456789");

// 编写一个函数查找给定字符串中的每个数字字符，并打印查找结果，然后接着查找每个字母，并打印结果
// 注意：find_each1只能用string类的find_first_of成员函数
void find_each1(string s) {
    string::size_type pos1 = 0;
    // 查找字符串s中的每个数字字符
    while ((pos1 = s.find_first_of(numbers, pos1)) != string::npos) {
        cout << "found number at index: " << pos1
             << " element is " << s[pos1] << endl;
        ++pos1;
    }
    // 接着查找每个字母
    string::size_type pos2 = 0;
    while ((pos2 = s.find_first_of(letters, pos2)) != string::npos) {
        cout << "found letter at index: " << pos2
             << " element is " << s[pos2] << endl;
        ++pos2;
    }
}

// 另一个版本，只能用find_first_not_of成员函数
void find_each2(string s) {
    string::size_type pos1 = 0;
    // 查找字符串s中的每个数字字符
    while ((pos1 = s.find_first_not_of(letters, pos1)) != string::npos) {
        cout << "found number at index: " << pos1
             << " element is " << s[pos1] << endl;
        ++pos1;
    }
    // 接着查找每个字母
    string::size_type pos2 = 0;
    while ((pos2 = s.find_first_not_of(numbers, pos2)) != string::npos) {
        cout << "found letter at index: " << pos2
             << " element is " << s[pos2] << endl;
        ++pos2;
    }
}

int main()
{
    string s("ab2c3d7R4E6");
    cout << "Call the function of version 1th:" << endl;
    find_each1(s);
    cout << "\nCall the function of version 2th:" << endl;
    find_each2(s);
}