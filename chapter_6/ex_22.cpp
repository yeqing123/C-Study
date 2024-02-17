#include <iostream>
using namespace std;
// 函数swap_pointer交换两个int指针
void swap_pointer(const int* &p1, const int* &p2)
{
    const int* temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int i = 20, j = 42;
    // 指针ip和jp指向两个整型变量i和j，并设置各一个底层const，即不可通过指针改变其所指的整型变量的值
    const int *ip = &i, *jp = &j;  
    // 调用函数交换两个指针的值
    swap_pointer(ip, jp);
    cout << "*ip = " << *ip << "\n*jp = " << *jp << endl;
    // 两个整型变量的值不变
    cout << "i = " << i << "\nj = " << j << endl;
    return 0;
}