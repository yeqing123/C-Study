#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str, result;
    // 输入一行带标点符号的字符串
    getline(cin, str);     // 虽然输入流最后的换行符也会被读进来，但是不会被存入字符串str中
    // 遍历每个字符
    for (auto c : str) {
        // 将所有不是标点符号的字符，加入到字符串result中
        if (!ispunct(c)) {
            result += c;
        }
    }
    cout << result << endl;
    return 0;
}