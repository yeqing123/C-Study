#include <iostream>
using namespace std;
// 修改ex_10中的函数，通过引用形参交换两个整数的值
void swap(int &a, int &b) 
{
    // 如果两个参数的值相等，则直接退出
    if (a == b) {
        return;
    }
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 0, j = 42;
    // 调用函数交换变量i和变量j的值
    swap(i, j);
    cout << "i = " << i << "\nj = " << j << endl;
    return 0;
}