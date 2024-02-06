#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> iv{2, 4, 5, 7, 9, 1, 8, 3, 6, 10};  // 定义包含10个整数的向量
    // 使用迭代器将所有元素的值修改为原来的二倍
    for (auto it = iv.begin(); it != iv.end(); ++it) {
        *it *= 2;
    }
    // 输出修改后的结果
    for (auto it = iv.begin(); it != iv.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}