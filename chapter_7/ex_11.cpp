#include <iostream>
#include "Sales_data_v3.h"
using namespace std;
// 使用Sales_data_v3中添加的四个构造函数来定义对象
int main()
{
    Sales_data_v3 sd1;  // 使用了默认构造函数
    Sales_data_v3 sd2("ABCD-EF");  // 使用只有一个形参的构造函数
    Sales_data_v3 sd3("abcd-ef", 3, 10.5); // 使用有三个形参的构造函数（10.5是书的单价）
    Sales_data_v3 sd4(cin);    // 使用了输入流为形参的构造函数，它将从输入流中读取数据

    print(cout, sd1) << endl;
    print(cout, sd2) << endl;
    print(cout, sd3) << endl;
    print(cout, sd4) << endl;
    return 0;
}