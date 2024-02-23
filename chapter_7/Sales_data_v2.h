#ifndef SALES_DATA_V2_H
#define SALES_DATA_V2_H
#include <string>
struct Sales_data_v2 {
    std::string bookNo;   // 书的ISBN编号
    unsigned units_sold = 0; // 销售量
    double revenue = 0.0;   // 销售收益
    // 返回bookNo
    std::string isbn() const 
    {
        return bookNo;
    }
    // 用传入的实参，更新调用该函数的Sales_data_v2对象
    Sales_data_v2 &combine(const Sales_data_v2 &rsd)
    {
        units_sold += rsd.units_sold;
        revenue += rsd.revenue;
        return *this;
    }
    // 声明成员函数avg_price
    double avg_price() const;
};
// 在类的外部定义成员函数
double Sales_data_v2::avg_price() const 
{
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

// 声明三个非成员接口函数
std::istream &read(std::istream&, Sales_data_v2&);
std::ostream &print(std::ostream&, const Sales_data_v2&);
Sales_data_v2 add(const Sales_data_v2&, const Sales_data_v2&);
#endif