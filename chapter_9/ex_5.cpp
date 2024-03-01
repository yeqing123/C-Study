#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
// 修改上一题，返回迭代器指向找到的元素
vector<int>::const_iterator find_value(vector<int>::const_iterator begin, vector<int>::const_iterator end, int val) {
    while (begin != end) {
        if (*begin == val) {  // 找到了给定的值
            return begin;
        }
        ++begin;            // 迭代器begin递增
    }
    return begin;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    int val = 9;
    // 在两个迭代器范围内查找val
    vector<int>::const_iterator it = find_value(vec.begin(), vec.end(), val);
    // 程序必须处理没有找到给定值的情况
    if (it != vec.end()) {
        cout << *it << " is present in the container." << endl;
    } else {
        cout << "The value you are looking for does not exist in the container ." << endl;
    }
    return 0;
}