#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<string> sli;
    string s;
    //  从标准输入流中读取string序列
    while (cin >> s) {
        sli.push_back(s);
    }
    // 使用迭代器打印list中的元素
    for (list<string>::const_iterator it = sli.cbegin(); it != sli.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}