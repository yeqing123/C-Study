#include <iostream>
#include <forward_list>
#include <string>
using namespace std;
// prosecss函数接受一个forward_list<string>对象和两个string，
// 如果在链表中找到了第一个string就紧接着在其后面插入第二个string，
// 否则就在链表的末尾添加第二个string。
void process(forward_list<string> &flst, string s1, string s2) {
    // 维护两个迭代器，prev初始化为链表首元素的前一个不存在的位置，curr初始化为链表的首个元素
    forward_list<string>::iterator prev = flst.before_begin();
    forward_list<string>::iterator curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr == s1) {
            flst.insert_after(curr, s2);
            return;
        } else {
            prev = curr;  // prev和curr都向前移一位
            ++curr;
        }
    }
    // 如果在链表中没有找到s2，则在链表的末尾处添加s2
    flst.insert_after(prev, s2);  // prev在链表的最后一个元素的位置，故在prev后面插入s2
    return;
}

int main()
{
    forward_list<string> flst{"banana", "peach", "orange", "watermelon"};
    process(flst, "peach", "blueberry");  // 在peach的后面插入buluberry
    // 打印处理后的结果
    for (auto s : flst) {
        cout << s << " ";
    }
    cout << endl;
    process(flst, "apple", "pear");      // 因为链表中没有字符串apple，所以在链表末尾插入pear
    // 打印处理后的结果
    for (auto s : flst) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}