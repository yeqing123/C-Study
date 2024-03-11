#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
/*
* 修改ex_20，使其找到的重复单词必须以大写字母开头
*/
int main()
{
    string prestr, currstr;
    bool bl;    // 定义一个布尔值，用来标记是否存在以大写字母开始的字符串连续重复出现的情况
    cout << "Please enter some strings:" << endl;
    while (cin >> currstr) {
        bl = false;
        if (!isupper(currstr[0])) {  // 如果字符串不是以大写字母开头的，则终止本次循环，执行下一次循环
            continue;
        }
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
        cout << "Does not start with a capital letter string repeated continuously!" << endl;
    }
    
    return 0;
}