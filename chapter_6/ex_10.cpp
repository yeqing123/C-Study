#include <iostream>
using namespace std;
// 函数通过指针形参交换两个整数的值
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i = 0, j = 42;
    // 调用函数交换变量i和变量j的值
    swap(&i, &j);
    cout << "i = " << i << "\nj = " << j << endl;
    return 0;
}