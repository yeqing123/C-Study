#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str, result;
    cout << "Enter a line of string(try method one): " << endl;
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
    cin.clear();
    cin.sync();

    cout << "It's great! Try method two, still enter a line of string: " << endl;
    getline(cin, str);
    for (decltype(str.size()) i = 0; i < str.size(); ++i) {
        if (!ispunct(str[i])) {
            // 这次我们直接打印每个字符
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}