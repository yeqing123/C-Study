#include <iostream>
using namespace std;
// 定义函数，计算参数val的阶乘，并返回结果
int fact(int val)
{
    int result = 1;   // 保存计算结果
    while (val > 1) {
        result *= val--;
    }
    return result;
}

int main() {
    // 调用fact函数，计算5的阶乘(结果应该是120)
    cout << "5! is: " << fact(5) << endl;
    return 0;
}