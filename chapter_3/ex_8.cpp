#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str1 = "first string";
    string::size_type index = 0; // 下标使用string::size_type类型，防止其小于0
    // 分别使用while循环和传统的for循环，分别将字符串str1和str2中的所有字符转换成字符X
    while (index < str1.size()) {
        str1[index] = 'X';
        index++;
    }
    cout << str1 << endl;

    string str2 = "second string";
    for (string::size_type i = 0; i != str2.size(); ++i) {
        str2[i] = 'X';
    }
    cout << str2 << endl;
    return 0;
}