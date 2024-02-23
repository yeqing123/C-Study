#include <iostream>
#include "Screen.h"
using namespace std;

int main()
{
    string::size_type width = 5, height = 4;  // 定义屏幕的宽度和高度
    // 使用三个不同的构造函数创建Screen对象
    Screen sn1;      // 由默认构造函数创建的对象
    Screen sn2(height, width);
    Screen sn3(height, width, 'c');  
    // 打印三个对象，验证是否创建成功
    cout << "----sn1------" << endl;
    sn1.display(cout);       // sn1中contents为空
    cout << endl;
    cout << "----sn2------" << endl;
    sn2.display(cout);    // sn2中包含了指定数量的空白字符
    cout << endl;
    cout << "----sn3------" << endl;
    sn3.display(cout);    // sn3中包含了指定数量的给定字符
    cout << endl;

    return 0;
}