#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m = {{"aaa", 2}, {"bbb", 4}, {"ccc", 6}};
    map<string, int>::key_type k = "bb";     // 定义下标变量，k为string类型
    map<string, int>::mapped_type v = m[k];   // 定义下标操作的返回值变量，v为int类型
    // 如果没有下标对应的元素，map会创建一个关键字为“bb”，值为0的新元素
    v = 7;                                   // 修改v的值，并不会对map造成任何影响，因为v是m[k]的拷贝
    cout << v << endl;
    cout << m[k] << endl;       

    return 0;
}