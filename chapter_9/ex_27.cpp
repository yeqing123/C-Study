#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    // 删除forward_list<int>中的奇数元素
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int>::iterator prev = flst.before_begin(), curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);   // 因为curr所指的元素已经被删除，所有要重置curr
        } else {                             // 两个迭代器前移一位
            prev = curr;
            ++curr;
        }
    }
    // 打印结果
    for (auto elem : flst) {
        cout << elem << endl;
    }
    return 0;
}