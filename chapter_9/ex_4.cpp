#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
// find函数接受两个const_iterator类型的迭代器，和一个int值，
// 在迭代器范围内查找是否存在整数，并返回布尔值
bool find_value(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i) {
    while (begin != end) {
        if (*begin == i) {  // 找到了整数i
            return true;
        }
        ++begin;            // 迭代器begin递增
    }
    return false;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    // 在两个迭代器范围内查找数字4
    cout << find(vec.begin(), vec.end(), 1) << endl;
    return 0;
}