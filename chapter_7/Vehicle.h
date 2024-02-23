// 定义有关交通工具的类
#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
class Vehicle {
public:
    // Vehicle() = default;   // 也可以写成：Vehicle(string k = ""); 等价的
    Vehicle(std::string k, unsigned n, double s) : kind(k), loadage(n), speed(s) { }
    // 也可以使用委托构造函数
    Vehicle() : Vehicle("", 0, 0) { }
    Vehicle(std::istream& is) : Vehicle() { this->reset(is); };

    std::string get_kind() const {
        return kind;
    }
    Vehicle &reset(std::istream&);  // 重新输入对象的内容
    std::ostream &display(std::ostream&) const;    // 向输出流写入成员数据
    bool isEmpty() const;   // 判断对象是否为空
private:
    std::string kind;   // 交通工具的种类，如：飞机、小汽车、火车等
    unsigned loadage = 0;   // 载客人数
    double speed = 0;  // 速度，每小时英里数
};

Vehicle &Vehicle::reset(std::istream &is) {
    is >> kind >> loadage >> speed;
    return *this;
}

std::ostream &Vehicle::display(std::ostream &os) const {
    os << kind << " " << loadage << " " << speed << "(mph)";
    return os;
}

bool Vehicle::isEmpty() const {
    return (kind.empty() && loadage == 0 && speed == 0);
}
#endif