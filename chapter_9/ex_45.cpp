#include <iostream>
#include <string>
using namespace std;
// 函数complete_address使用迭代器以及insert和append函数，将前缀prefix和后缀suffix添加了人名name的相应位置，并返回结果
string complete_address(string name, string prefix, string suffix) {
    if (prefix != "") {  // 如果前缀不为空，则给它后面加一个空格
        prefix.append(" ");
    }
    if (suffix != "") {  // 如果后缀不为空，则给它前面加一个空格
        string s = " ";
        suffix.insert(suffix.begin(), begin(s), end(s));
    }
    name.insert(name.begin(), prefix.begin(), prefix.end());  // 在人名的首位插入前缀
    name.append(suffix);                                      // 在人名的末尾加入后缀
    return name;
}

int main()
{
    string address1 = complete_address("YeQing", "Mr.", "Ph.D.");
    cout << address1 << endl;
    string address2 = complete_address("LiuChangYun", "", "Jr.");
    cout << address2 << endl;
    string address3 = complete_address("John Doe", "Dr.", "");
    cout << address3 << endl;
    string address4 = complete_address("Johnson", "", "III");
    cout << address4 << endl;
    return 0;
}