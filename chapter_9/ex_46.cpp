#include <iostream>
#include <string>
using namespace std;
// complete_address函数的另一个版本，使用位置和长度来管理string，并只使用insert
string complete_address(string name, string prefix, string suffix) {
    if (prefix != "") {  // 如果前缀不为空，则给它后面加一个空格
        prefix.insert(prefix.size(), " ");
    }
    if (suffix != "") {  // 如果后缀不为空，则给它前面加一个空格
        suffix.insert(0, " ");
    }
    name.insert(0, prefix);            // 在name的首个字符的前面插入prefix
    name.insert(name.size(), suffix);  // 在name的末尾字符的后面插入suffix
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