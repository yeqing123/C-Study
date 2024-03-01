#include <iostream>
#include <string>
using namespace std;
// my_replace的另一个版本
// 重写上一题，使用一个下标和replace函数完成同样的任务
string my_replace(string s, string oldStr, string newStr) {
    // 使用下标遍历字符串s
    if (oldStr.size() > 0) {                                 // 必须保证oldStr长度大于0
        for (unsigned i = 0; i != s.size(); ++i) {
            if (s[i] == oldStr.at(0)) {                      // 当下标i位置的字符等于oldStr的首个字符时
                string subStr = s.substr(i, oldStr.size()); // 从s中下标位置i开始，拷贝出与oldStr相同长度的字符
                if (subStr == oldStr) {                     // 比较子串subStr与oldStr是否相同
                    s.replace(i, oldStr.size(), newStr);    // 如果相同说明可以将s中与i对应位置的字符串替换为newStr
                    return s;
                }
            }
        }
    }
    return s;
}

int main()
{
    // 将s1中的字符串“tho”替换为“though”
    string s1("Even tho I'm quite a reserved person, I like meeting people.");
    s1 = my_replace(s1, "tho", "though");
    cout << s1 << endl;
    // 将s2中的字符串“thru”替换为“through”
    string s2("A brilliant shaft of sunlight burst thru the doorway.");
    s2 = my_replace(s2, "thru", "through");
    cout << s2 << endl;
    // 将s3中的字符串“strong”替换为“highly active”
    string s3("My program is very strong!");
    s3 = my_replace(s3, "strong", "highly active");
    cout << s3 << endl;
    return 0;
}