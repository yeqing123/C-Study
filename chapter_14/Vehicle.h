// 定义有关交通工具的类
#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>

class Vehicle {
friend std::ostream &operator<<(std::ostream&, const Vehicle &);
friend std::istream &operator>>(std::istream&, Vehicle &);
friend bool operator==(const Vehicle &, const Vehicle &);
friend bool operator!=(const Vehicle &, const Vehicle &);
public:
    // Vehicle() = default;   // 也可以写成：Vehicle(string k = ""); 等价的
    Vehicle(std::string k, unsigned n, double s) : kind(k), loadage(n), speed(s) { }
    // 也可以使用委托构造函数
    Vehicle() : Vehicle("", 0, 0) { }
    Vehicle(std::istream& is) : Vehicle() { this->reset(is); };
    Vehicle &operator=(const Vehicle&);   // 拷贝赋值运算符
    std::string get_kind() const {
        return kind;
    }
    Vehicle &reset(std::istream&);               // 重新输入Vehicle对象的内容
    bool isEmpty() const;                        // 判断对象是否为空
    // 完成练习14.49，添加转换目标是bool的类型转换运算符
    // 判断是否数据成员是否为空，不为空返回true，反之返回false
    explicit operator bool() const { return !isEmpty(); }
private:
    std::string kind;               // 交通工具的种类，如：飞机、小汽车、火车等
    unsigned loadage = 0;           // 载客人数
    double speed = 0;               // 速度，每小时英里数
};

Vehicle &Vehicle::reset(std::istream &is) {
    is >> kind >> loadage >> speed;
    return *this;
}

inline bool Vehicle::isEmpty() const {
    return (kind.empty() && loadage == 0 && speed == 0);
}

// 拷贝赋值运算符
inline Vehicle &Vehicle::operator=(const Vehicle &v)
{
    kind = v.kind;
    loadage = v.loadage;
    speed = v.speed;
}

// 重载输出运算符
std::ostream& operator<<(std::ostream &os, const Vehicle &vic) {
    os << vic.kind << " " << vic.loadage << " " << vic.speed << "(mph)";
    return os;
}

// 重载输入运算符
std::istream &operator>>(std::istream &in, Vehicle &vic)
{
    in >> vic.kind >> vic.loadage >> vic.speed;
    if (!in) {
        vic = Vehicle();
    }
    return in;
}

bool operator==(const Vehicle &r, const Vehicle &l)
{
    if (r.kind == l.kind && r.loadage == l.loadage && r.speed == l.speed) {
        return true;
    }
    return false;
}

bool operator!=(const Vehicle &r, const Vehicle &l)
{
    return !(r == l);
}
#endif