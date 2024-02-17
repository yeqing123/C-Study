#include <iostream>
using namespace std;
void fun(int val) 
{
    int n = 0;    // 局部变量
    static int sn = 0;   // 局部静态变量
    cout << "val:" << val << "\tn:" << n
         << "\tsn:" << sn << endl;

    // 局部变量和形参在函数执行完毕后，就会被销毁。而局部静态变量会一直存在直至程序终结
    val++;    
    n++;      
    sn++;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        fun(1);  // 只有sn的值会一个保存
    }
    return 0;
}