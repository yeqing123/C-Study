#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string prestr, currstr;
    bool bl;    // 定义一个布尔值，用来标记是否存在一个字符串连续重复出现的情况
    cout << "Please enter some strings:" << endl;
    while (cin >> currstr) {
        bl = false;
        if (prestr == currstr) {
            bl = true;
            break;    // 结束while循环
        } else { 
            prestr = currstr;
        }
    }
    if (bl) {  // 如果bl为真，则有重复出现的字符串，否则就是没有
        cout << "String '" << currstr << "' appears repeatedly continuously." << endl;
    } else {
        cout << "No string is repeated continuously!" << endl;
    }
    
    return 0;
}