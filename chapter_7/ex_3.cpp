#include <iostream>
#include <string>
#include "Sales_data_v2.h"
using namespace std;
// 定义在Sales_data_v2中声明的read、print两个非成员函数接口
istream &read(std::istream &is, Sales_data_v2 &sd)
{
    double price = 0.0;
    is >> sd.bookNo >> sd.units_sold >> price;
    // 计算销售收益
    sd.revenue = sd.units_sold * price;
    return is;
}

ostream &print(std::ostream &os, const Sales_data_v2 &sd) 
{
    // 输出上一本书的结果
    os << sd.isbn() << " " << sd.units_sold << " "
         << sd.revenue << " " << sd.avg_price();  // 一般负责输出的函数不负责进行格式控制，因此末尾无须换行 
    return os;
}

int main()
{
    Sales_data_v2 total;
    double price = 0.0;   // 书的单价
    if (read(cin, total)) {
        Sales_data_v2 trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);   // 更新变量total当前的值
            } else {
                // 打印上一本书的结果
                print(cout, total) << endl;
                // 别忘了更新total变量
                total = trans;
            }
        }
        // 输出最后一本书的结果
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}