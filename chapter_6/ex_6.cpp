#include <iostream>
using namespace std;
void fun(int val) 
{
    int n = 0;    // 局部变量
    static int sta_n = 0;   // 局部静态变量
    cout << "val:" << val << "\tn:" << n
         << "\tsn:" << sta_n << endl;
    // 局部变量和形参在函数执行完毕后就会被销毁。而局部静态变量会一直存在直至程序终结
    n += val;
    sta_n += val;
    val += 1;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        fun(1);  // 只有sta_n的值会一个保存
    }
    return 0;
}