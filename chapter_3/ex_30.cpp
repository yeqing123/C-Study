#include <iostream>
using std::cout;
using std::endl;
int main()
{
    // 定义个int类型的数组，让每个元素的值与其所在下标相等
    int ia[10];
    for (size_t index = 0; index < 10; ++index) {
        ia[index] = index;
    }
    for (auto i : ia) {
        cout << i << endl;
    }
    return 0;
}