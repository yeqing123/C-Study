#include <iostream>
using namespace std;

int factorial(int val)
{
    if (val != 0) {
        cout << val << " * ";  // 输出阶乘计算式，查看计算过程
        return factorial(val - 1) * val;
    }
    cout << 1 << endl;
    return 1;
}

int main()
{
    factorial(5);   // 输出结果为：5 * 4 * 3 * 2 * 1 * 1
    return 0;
}
