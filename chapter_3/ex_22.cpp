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
    vector<string> text{"I am Jessica.", 
                        "I live in a city of India.",
                        "",        // 表示段落分隔的空字符串
                        "My favorite colour is pink.", 
                        "And my favorite clothes are dresses."};

    // 使用迭代器遍历每个字符串，直至遇到空字符为止
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        // 将字符串全部修改为大写形式
        for (auto &c : *it) {
            c = toupper(c);
        }
    }
    // 输出修改后的第一段文字
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }
    return 0;
}