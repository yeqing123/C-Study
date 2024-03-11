#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

using namespace std;

class Sales_data {
// 声明友元函数
friend ostream& operator << (ostream&, const Sales_data&);
friend istream& operator >> (istream&, Sales_data&);
friend bool operator == (const Sales_data&, const Sales_data&);
friend bool operator != (const Sales_data&, const Sales_data&);
friend bool operator < (const Sales_data&, const Sales_data&);
friend Sales_data operator + (const Sales_data&, const Sales_data&);
friend bool compareIsbn(const Sales_data&, const Sales_data&);
public:
    Sales_data() {};
    Sales_data(string &book) : bookName(book) {}
    Sales_data(istream &is) { is >> *this; }
    Sales_data& operator += (const Sales_data&);
    string isbn() const { return bookName; }
private:
    string bookName;   // 书名
    unsigned units_sold = 0;    // 销量
    double sellingprice = 0.0;  // 实卖价
    double salesprice = 0.0;    // 零售价
    double discount = 0.0;      // 折扣
};

inline ostream& operator << (ostream &os, const Sales_data &sd)
{
    os << "ISBN: " << sd.bookName << " \\units sold: " << sd.units_sold 
       << " \\sales price: " << sd.salesprice << " \\selling price: " << sd.sellingprice 
       << " \\sales_revenue: " << sd.units_sold * sd.sellingprice << " \\discount: " << sd.discount;
    return os;
}

inline istream& operator >> (istream &is, Sales_data &sd)
{
    is >> sd.bookName >> sd.units_sold >> sd.salesprice >> sd.sellingprice;

    if (is && sd.salesprice != 0 && sd.sellingprice != 0) {
        sd.discount = (sd.sellingprice / sd.salesprice) * 10;
    } else if (sd.salesprice == 0) {
        cerr << "sales price can't is 0! ISBN: " << sd.isbn() 
             << ". A blank record has been created for the book."<< endl;
        sd = Sales_data(sd.bookName);
    }
    return is;
}

inline bool operator == (const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() == sd2.isbn() && 
        sd1.salesprice == sd2.salesprice &&
        sd1.sellingprice == sd2.sellingprice &&
        sd1.units_sold == sd2.units_sold;
}

inline bool operator != (const Sales_data &sd1, const Sales_data &sd2)
{
    return !(sd1 == sd2);
}

inline bool operator < (const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

inline Sales_data operator + (const Sales_data &sd1, const Sales_data &sd2)
{
    Sales_data sum = sd1;
    sum += sd2;
    return sum;
}

inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) 
{
    return sd1.isbn() == sd2.isbn();
}

Sales_data& Sales_data::operator += (const Sales_data &sd)
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
#endif