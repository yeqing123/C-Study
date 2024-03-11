#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    list<int> lst1, lst2, lst3;
    // 将vec中位置3到7之间的元素(3、4、5、6、7)按逆序拷贝到list中
    // 注意copy执行拷贝时区间中最后一位不包含在内，因此需要多后移一位
    // 思路一：
    vector<int>::reverse_iterator r_end1(vec.begin() + 3);
    vector<int>::reverse_iterator r_begin1(vec.begin() + 7);
    copy(r_begin1, r_end1 + 1, inserter(lst1, lst1.begin()));
    for (auto i : lst1) {
        cout << i << " ";
    }
    cout << endl;
    // 思路二：
    auto r_end2 = vec.crend() - 3;
    auto r_begin2 = vec.crend() - 7;
    copy(r_begin2, r_end2 + 1, inserter(lst2, lst2.begin()));
    for (auto i : lst2) {
        cout << i << " ";
    }
    cout << endl;
    // 思路三：
    copy(vec.cbegin() + 2, vec.cbegin() + 7, front_inserter(lst3));
    for (auto i : lst3) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}