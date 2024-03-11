#include <iostream>

using namespace std;

int main()
{
    int i = 2, j = 4, k = 0;
    auto r1 = i != j < k;
    auto r2 = i != (j < k);
    auto r3 = (i != j) < k; 
    cout << "r1 = " << r1 << endl;   // r1 = 1
    cout << "r2 = " << r2 << endl;   // r2 = 1
    cout << "r3 = " << r3 << endl;   // r3 = 0
    // 从输出的结果可以看出：i != j < k 等价于 i != (j < k)
    // 这也验证了C++规定运算符>、<、>=、<=的优先级高于==和!=运算符。
    return 0;
}