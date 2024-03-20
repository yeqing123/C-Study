#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print(const string &s)
{
    cout << s << " ";
}

int main() 
{
    multiset<string> c = {"helle", "world", "abc"};
    vector<string> v = {"Hi!", "C++"};
    // 因为set只有insert函数用来插入元素，并且无法指定位置，
    // 插入元素时set会自动按升序排序，所以使用inserter插入器
    // 指定插入位置是没有意义的。
    copy(v.begin(), v.end(), inserter(c, c.end()));
    // 打印拷贝后的结果
    cout << "c: ";
    for_each(c.begin(), c.end(), print);
    cout << endl;
    // 因为插入器back_inserter需要调用目标容器的push_back函数来添加元素，
    // 但是set没有定义该函数，所以会报错。其他拷贝语句都是正确的。
    copy(v.begin(), v.end(), back_inserter(c));     // 错误！

    copy(c.begin(), c.end(), inserter(v, v.end()));
    // 打印拷贝后的结果
    cout << "v: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    copy(c.begin(), c.end(), back_inserter(v));
    // 打印拷贝后的结果
    cout << "v: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}