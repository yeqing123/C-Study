#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> v1 = {0, 1, 1, 2, 3}, v2 = {0, 1, 1, 2, 3, 5, 8};
    // 获取两个vector对象的迭代器
    auto begin1 = v1.begin(), begin2 = v2.begin();
    // 遍历两个迭代器，测试其中一个是否为另一个的前缀
    while (begin1 != v1.end() && begin2 != v2.end()) {
        if (*begin1 != *begin2) {
            break;
        }
        ++begin1;
        ++begin2;
    }
    if (begin1 == v1.end() && begin2 != v2.end()) {
        cout << "v1 is v2's prefix." << endl;
    } else if (begin1 != v1.end() && begin2 == v2.end()) {
        cout << "v2 is v1's prefix." << endl;
    } else if (begin1 == v1.end() && begin2 == v2.end()) {
        cout << "v1 equals v2." << endl;
    } else {        // 当出现“begin1 != v1.end() && begin2 != v2.end()”这种情况时，说明两个vector对象互不相等
        cout << "v1 and v2 are not prefix to each other." << endl;
    }
    return 0;
}