#include <iostream>
using namespace std;
// compare_val函数比较两个整数的大小，返回较大的那个
int compare_val(const int a, const int* p) // 第二个形参类型为指向整型常量的指针
{
    return a > *p ? a : *p;
}

int main()
{
    int i = 20, j = 12;
    cout << "Digit of larger is: " << compare_val(i, &j);
    return 0;
}