#ifndef SALES_DATA_V3_H
#define SALES_DATA_V3_H
#include <string>
struct Sales_data_v3 {
private:
    std::string bookNo;   // 书的ISBN编号
    unsigned units_sold = 0; // 销售量
    double revenue = 0.0;   // 销售收益
    // 声明成员函数avg_price
    double avg_price() const;
public:
    // 定义构造函数
    Sales_data_v3() = default;
    Sales_data_v3(const std::string &s) : bookNo(s) {}  // 函数体为空
    Sales_data_v3(const std::string &s, unsigned n, double p) :  // 参数p是书的单价
        bookNo(s), units_sold(n), revenue(n*p) {}  
    Sales_data_v3(std::istream &is);  // 声明一个以输入流为形参的构造函数，该函数将在类的外部被定义
    // 也可以直接将它定义在类的内部
    // Sales_data_v3(std::istream &is)
    // {
    //     double price = 0.0;
    //     is >> bookNo >> units_sold >> price;
    //     // 计算销售收益
    //     revenue = units_sold * price;
    // }
    // 返回bookNo
    std::string isbn() const 
    {
        return bookNo;
    }
    // 用传入的实参，更新调用该函数的Sales_data_v2对象
    Sales_data_v3 &combine(const Sales_data_v3 &rsd)
    {
        units_sold += rsd.units_sold;
        revenue += rsd.revenue;
        return *this;
    }
    // 将非成员函数声明为友元
    friend std::istream &read(std::istream&, Sales_data_v3&);
    friend std::ostream &print(std::ostream&, const Sales_data_v3&);
    friend Sales_data_v3 add(const Sales_data_v3&, const Sales_data_v3&);
};

// 声明三个非成员接口函数
std::istream &read(std::istream&, Sales_data_v3&);
std::ostream &print(std::ostream&, const Sales_data_v3&);
Sales_data_v3 add(const Sales_data_v3&, const Sales_data_v3&);

// 在类的外部定义成员函数(并应练习26的要求，将其定义成内联函数)
inline double Sales_data_v3::avg_price() const 
{
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

// 定义构造函数Sales_data_v3(std::istream);
Sales_data_v3::Sales_data_v3(std::istream &is)
{
    read(is, *this);   // 因为read函数的第二个参数是正在构造的Sales_data_v3对象本身，因此用隐式形参this的解引用表示。
}

// 定义read、print和add三个非成员接口函数
std::istream &read(std::istream &is, Sales_data_v3 &sd)
{
    double price = 0.0;
    is >> sd.bookNo >> sd.units_sold >> price;
    // 计算销售收益
    sd.revenue = sd.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data_v3 &sd) 
{
    // 输出上一本书的结果
    os << sd.isbn() << " " << sd.units_sold << " "
         << sd.revenue << " " << sd.avg_price();  // 一般负责输出的函数不负责进行格式控制，因此末尾无须换行 
    return os;
}

Sales_data_v3 add(const Sales_data_v3 &lsd, const Sales_data_v3 &rsd) 
{
    Sales_data_v3 sum = lsd;  // 拷贝一个lsd的副本给sum变量
    sum.combine(rsd);  // 把rsd的数据成员加到sum当中
    return sum;
}
#endif