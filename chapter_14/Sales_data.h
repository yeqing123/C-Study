#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

using namespace std;

class Sales_data {
// 声明友元函数
friend ostream& operator<<(ostream&, const Sales_data&);
friend istream& operator>>(istream&, Sales_data&);
friend bool operator==(const Sales_data&, const Sales_data&);
friend bool operator!=(const Sales_data&, const Sales_data&);
friend bool operator<(const Sales_data&, const Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend Sales_data operator-(const Sales_data&, const Sales_data&);
friend bool compareIsbn(const Sales_data&, const Sales_data&);
public:
    Sales_data() {};
    Sales_data(string &book) : bookName(book) {}
    Sales_data(istream &is) { is >> *this; }
    Sales_data& operator=(const string&);  // 接受表示ISBN的string，将其赋给=左侧的Sales_data对象
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    string isbn() const { return bookName; }
    // 定义类型转换运算符
    operator string() const;
    operator double() const;    
private:
    string bookName;   // 书名
    unsigned units_sold = 0;    // 销量
    double sellingprice = 0.0;  // 实卖价
    double salesprice = 0.0;    // 零售价
    double discount = 0.0;      // 折扣
};

inline Sales_data& Sales_data::operator=(const string &s)
{
    bookName = s;
    return *this;
}

inline ostream& operator<<(ostream &os, const Sales_data &sd)
{
    os << "ISBN: " << sd.bookName << "  units sold: " << sd.units_sold 
       << "  average price: " << sd.salesprice << "  average selling price: " << sd.sellingprice 
       << "  sales_revenue: " << sd.units_sold * sd.sellingprice << "  discount: " << sd.discount;
    return os;
}

inline istream& operator>>(istream &is, Sales_data &sd)
{
    is >> sd.bookName >> sd.units_sold >> sd.salesprice >> sd.sellingprice;

    if (is && sd.salesprice != 0) {     // 检查输入是否失败，并且salesprice作为被除数也不能为0
        sd.discount = (sd.sellingprice / sd.salesprice) * 10;
    } else {
        sd = Sales_data();              // 如果出现错误，对象被置于默认状态
    }
    return is;
}

inline bool operator==(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() == sd2.isbn() && 
        sd1.salesprice == sd2.salesprice &&
        sd1.sellingprice == sd2.sellingprice &&
        sd1.units_sold == sd2.units_sold;
}

inline bool operator!=(const Sales_data &sd1, const Sales_data &sd2)
{
    return !(sd1 == sd2);
}

inline bool operator<(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

inline Sales_data operator+(const Sales_data &sd1, const Sales_data &sd2)
{
    Sales_data sum = sd1;
    sum += sd2;
    return sum;
}

inline Sales_data operator-(const Sales_data &sd1, const Sales_data &sd2)
{
    Sales_data sub = sd1;
    sub -= sd2;
    return sub;
}

inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) 
{
    return sd1.isbn() == sd2.isbn();
}

Sales_data& Sales_data::operator+=(const Sales_data &sd)
{
    salesprice = (salesprice * units_sold + sd.salesprice * sd.units_sold) / 
            (units_sold + sd.units_sold);
    sellingprice = (sellingprice * units_sold + sd.sellingprice * sd.units_sold) /
            (units_sold + sd.units_sold);
    
    if (salesprice != 0) {
        discount = (sellingprice / salesprice) * 10;
    }
    units_sold += sd.units_sold;   // 总销售量放在最后计算
}

Sales_data& Sales_data::operator-=(const Sales_data &sd)
{
    salesprice = (salesprice * units_sold - sd.salesprice * sd.units_sold) / 
            (units_sold - sd.units_sold);
    sellingprice = (sellingprice * units_sold - sd.sellingprice * sd.units_sold) /
            (units_sold - sd.units_sold);
    
    if (salesprice != 0) {
        discount = (sellingprice / salesprice) * 10;
    }
    units_sold -= sd.units_sold;   // 总销售量放在最后计算
}

Sales_data::operator string() const
{
    return "ISBN: " + bookName 
       + "  units sold: " + to_string(units_sold) 
       + "  average price: " + to_string(salesprice) 
       + "  average selling price: " + to_string(sellingprice) 
       + "  sales_revenue: " + to_string(units_sold * sellingprice) 
       + "  discount: " + to_string(discount);
} 

Sales_data::operator double() const{
    return units_sold * sellingprice;
}
#endif