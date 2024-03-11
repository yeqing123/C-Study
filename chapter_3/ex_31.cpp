#include <iostream>
using std::cout;
using std::endl;
int main()
{
    const int sz = 10;
    // 定义个int类型的数组，让每个元素的值与其所在下标相等
    int ia[sz];
    for (size_t index = 0; index < sz; ++index) {
        ia[index] = index;
    }
    for (auto i : ia) {
        cout << i << endl;
    }
    return 0;
}