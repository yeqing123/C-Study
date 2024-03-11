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
    cout << "Enter several strings this time(press Ctr+Z to end): " << endl;
    while (cin >> str) {
        // 将每个字符串“压”入vector对象的尾端
        strvec.push_back(str);
    }
    // 输出vector对象中的每个元素
    if (strvec.size() != 0) {
        cout << "Display all the elements of the container:" << endl;
        for (auto s : strvec) {
            cout << s << endl;
        }
    }else {
        cout << "The container is empty!" << endl;
    }
    return 0;
}