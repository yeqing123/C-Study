#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 使用普通迭代器，逆序打印元素
    for (auto iter = vec.cend() - 1; iter != vec.cbegin() - 1; --iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}