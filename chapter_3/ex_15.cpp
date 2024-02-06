#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    // 读入一组字符串，并存入一个vector对象中
    vector<string> strvec;
    string str;
    while (cin >> str) {
        // 将每个字符串“压”入vector对象的尾端
        strvec.push_back(str);
    }
    // 输出vector对象中的每个元素
    for (auto s : strvec) {
        cout << s << endl;
    }
    return 0;
}