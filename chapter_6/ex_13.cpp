#include <iostream>

using namespace std;

void a(int i)
{
    ++i;
}

void b(int &i)
{
    ++i;
}

int main()
{
    int i = 10;
    // a函数是传值方式，形参是实参的拷贝，所以形参改变不影响实参
    cout << "Before calling a(): i = " << i << endl;
    a(i);
    cout << "After calling a(): i = " << i << endl;
    // b函数是传引用方式，所以形参会绑定到实参，形参改变实参也会改变
    cout << "Before calling b(): i = " << i << endl;
    b(i);
    cout << "After calling b(): i = " << i << endl;
    return 0;
}