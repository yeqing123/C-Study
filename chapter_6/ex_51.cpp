#include <iostream>
using namespace std;
// 定义重载函数集
void f()
{
    cout << "I don't need any arguments!" << endl;
}

void f(int)
{
    cout << "I am \"f(int)\". I need one argument of type integer." << endl;
}

void f(int, int)
{
    cout << "I am \"f(int, int)\". I need two arguments of type integer." << endl;
}

void f(double, double = 3.14)
{
    cout << "I am \"f(double, double = 3.14)\". I need two arguments of type double." << endl;
}

int main()
{
    //f(2.56, 42);   编译器会报“二义性调用”错误
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}