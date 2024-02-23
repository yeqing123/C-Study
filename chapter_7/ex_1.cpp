// 利用2.6.1节定义的Sales_data类，编写书21页书店程序的新版本
// 因为Sales_data类中只有成员变量没有对应的操作，因此我们需要在程序中对其每个成员变量进行具体操作
#include <iostream>
#include "Sales_data_v1.h"
using namespace std;
int main()
{
    Sales_data_v1 total;
    double price = 0.0;  // 每本书的单价
    // 读入第一条交易记录，并确保有数据可以处理
    if (cin >> total.bookNo >> total.units_sold >> price) {
        // 计算销售收益
        total.revenue = price * total.units_sold;
        Sales_data_v1 trans;
        // 读入并处理剩余交易记录
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            // 计算销售收益
            trans.revenue = price * trans.units_sold;
            // 如果我们仍在处理相同的书
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // 打印前一本书的结果(输出的顺序是：ISBN, 销售量， 总收益， 平均单价)
                cout << total.bookNo << " " << total.units_sold << " " 
                     << total.revenue << " " << total.revenue / total.units_sold << endl;
                total = trans;    // total现在表示下一本书
            }
        }
        // 打印最后一本书的结果
        cout << total.bookNo << " " << total.units_sold << " " 
             << total.revenue << " " << total.revenue / total.units_sold << endl;
    } else {
        cout << "No data?!" << endl;
        return -1;
    }
    return 0;
}
