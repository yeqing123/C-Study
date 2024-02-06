#include <iostream>
#include <vector>
using std::begin;
using std::end;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    // 使用一个整型数组初始化一个vector对象
    int iarr[] = {2, 4, 6, 8, 10};
    vector<int> ivec(begin(iarr), end(iarr));
    // 打印vector对象
    for (auto i : ivec) {
        cout << i << endl;
    }
    return 0;
}