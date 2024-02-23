#include <iostream>
class Sales_data_simple {
public: 
    //Sales_data_simple(std::string s = "") : bookNo(s) {}  // 它会与接受istream&的构造函数产生冲突，造成二义性调用
    Sales_data_simple(std::string s, unsigned cnt, double p) : 
        bookNo(s), units_sold(cnt), revenue(cnt * p) {}
    // 定义为形参std::istream& 提供默认实参的构造函数
    Sales_data_simple(std::istream& is = std::cin) {
        double price;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
    }
    // 声明成员函数display，输出对象
    std::ostream& display(std::ostream&) const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

inline std::ostream& Sales_data_simple::display(std::ostream &os) const {
    
    os << this->bookNo << " " << this->units_sold << " " 
       << this->revenue / this->units_sold << " " << this->revenue;
    return os;
}

int main()
{
    // 使用了接受参数std::istream&的构造函数
    Sales_data_simple sd;
    sd.display(std::cout) << std::endl;
    return 0;
}