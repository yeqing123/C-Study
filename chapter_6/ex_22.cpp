#include <iostream>
using namespace std;
// 交换两个指针所指向的整数
// 因为是值传递，所以形参是局部变量，交互指针本身的值不影响函数外部的实参
void swap_pointer1(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
// 交换两个指针对象本身的值，但不交换它们所指对象的值
void swap_pointer2(int* &p1, int* &p2)
{
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int i = 20, j = 42;
    int *ip = &i, *jp = &j;  
    // 调用函数交换指针所指对象i和j的值，但指针对象本身的值不变
    cout << "------Test swap_pointer1 function------" << endl;
    cout << "Before swapping:" << endl;
    cout << "i = " << i << "\tj = " << j << endl;
    cout << "ip = " << ip << "\tjp = " << jp << endl;
    cout << "*ip = " << *ip << "\t*jp = " << *jp << endl;
    swap_pointer1(ip, jp);
    cout << "After swapping:" << endl;
    cout << "i = " << i << "\tj = " << j << endl;
    cout << "ip = " << ip << "\tjp = " << jp << endl;
    cout << "*ip = " << *ip << "\t*jp = " << *jp << endl;

    //为了便于观察，我们将i和j的值复原
    i = 20, j = 42;
    // 调用函数交换两个指针对象本身ip和jp的值，但是它们所指对象i和j的值不变
    cout << "\n------Test swap_pointer2 function------" << endl;
    cout << "Before swapping:" << endl;
    cout << "i = " << i << "\tj = " << j << endl;
    cout << "ip = " << ip << "\tjp = " << jp << endl;
    cout << "*ip = " << *ip << "\t*jp = " << *jp << endl;
    swap_pointer2(ip, jp);
    cout << "After swapping:" << endl;
    cout << "i = " << i << "\tj = " << j << endl;
    cout << "ip = " << ip << "\tjp = " << jp << endl;
    cout << "*ip = " << *ip << "\t*jp = " << *jp << endl;
    return 0;
}