#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<string> sdeq;
    string s;
    //  从标准输入流中读取string序列
    while (cin >> s) {
        sdeq.push_back(s);
    }
    // 使用迭代器打印deque中的元素
    for (deque<string>::const_iterator it = sdeq.cbegin(); it != sdeq.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}