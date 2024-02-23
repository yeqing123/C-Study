#ifndef SALES_DATA_V1_H
#define SALES_DATA_V1_H
#include <string>
struct Sales_data_v1 {
    std::string bookNo;   // 书的ISBN编号
    unsigned units_sold = 0; // 销售量
    double revenue = 0.0;   // 销售收益
};
#endif