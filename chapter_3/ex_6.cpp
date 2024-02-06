#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str = "one string";
    // 将字符串str中的每个字符转换成字符X
    for (auto &c : str) {
        c = 'X';
    }
    cout << str << endl;
    return 0;
}