#include <iostream>
#include <string>
using namespace std;
// my_replace函数接受三个string参数：s、oldStr和newStr，将字符串s中的oldStr替换为newStr。
// 该函数使用迭代器和erase、insert函数完成上述任务。
string my_replace(string s, string oldStr, string newStr) {
    // 从首字符开始查找s中oldStr的位置
    for (auto pos = s.begin(); pos != s.end(); ++pos) {   
        auto oldit = oldStr.begin();          // 每次循环时都获取位于oldStr首字符的迭代器
        auto sit = pos;                       // 保存pos所在位置，用于判断字符是否相同
        while (oldit != oldStr.end()) {       // 遍历oldStr的每个字符
            if (*oldit != *sit) {             // 使用两个迭代器判断其所在位置的字符是否相同，如果不同退出while循环
                break;
            } else {                          // 如果相同，则前移两个迭代器，继续比较下一个对字符
                ++sit;
                ++oldit;
            }
        }
        if (oldit == oldStr.end()) {            // 当遍历完oldStr中所有字符后，说明已经找到了要替换的位置
            s.erase(pos, pos + oldStr.size());  // 将pos到iter（不包含）指定迭代器范围中的字符删除
            s.insert(pos, newStr.begin(), newStr.end()); // 向pos所在的位置之前，插入整个newStr字符串
            return s;
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