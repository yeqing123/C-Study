#ifndef PERSON_H
#define PERSON_H
#include <string>
struct Person {
private:
    std::string name;
    std::string address;
public:
    Person() = default;  // 如果已经自定义了构造函数，则必须要有默认构造函数。
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}
    Person(std::istream&);

    std::string get_name() const 
    {
        return name;
    }
    std::string get_address() const
    {
        return address;
    }
    // 为Person类的非成员函数做的友元声明
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);
};

// 从输入流读取数据，并写入Person对象
std::istream &read(std::istream&, Person&);
// 打印Person对象
std::ostream &print(std::ostream&, const Person&);
// 定义istream参数的构造函数
Person::Person(std::istream &is)
{
    is >> name >> address;
}
#endif