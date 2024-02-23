#ifndef Sales_data_del_H
#define Sales_data_del_H
#include <string>
#include <iostream>
// 使用委托构造函数重新编写Sales_data类，取名Sales_data_del，并且删除了多余的成员
struct Sales_data_del {
private:
    std::string bookNo;   // 书的ISBN编号
    unsigned units_sold = 0; // 销售量
    double revenue = 0.0;   // 销售收益
public:
    // 只定义一个构造函数，其他的构造函数都委托该函数
    Sales_data_del(const std::string &s, unsigned n, double p) :  // 参数p是书的单价
        bookNo(s), units_sold(n), revenue(n*p) {
        std::cout << "\tCall the \"Sales_data_del(const std::string &s, unsigned n, double p)...\" construector." << std::endl;
    }  
    Sales_data_del() : Sales_data_del("", 0, 0) {
        std::cout << "\tCall the \"Sales_data_del()...\" default constructor." << std::endl;
    }
    Sales_data_del(const std::string &s) : Sales_data_del(s, 0, 0) {
        std::cout << "\tCall the \"Sales_data_del(const std::string &s)...\" constructor." << std::endl;
    }  
    Sales_data_del(std::istream &is) : Sales_data_del() { 
        std::cout << "\tCall the \"Sales_data_del(std::istream &is)...\" constructor." << std::endl;
        read(is, *this); 
    };
   
    // 将非成员函数声明为友元
    friend std::istream &read(std::istream&, Sales_data_del&);
};

// 声明三个非成员接口函数
std::istream &read(std::istream&, Sales_data_del&);

// 定义read、print和add三个非成员接口函数
std::istream &read(std::istream &is, Sales_data_del &sd)
{
    double price = 0.0;
    is >> sd.bookNo >> sd.units_sold >> price;
    // 计算销售收益
    sd.revenue = sd.units_sold * price;
    return is;
}
#endif