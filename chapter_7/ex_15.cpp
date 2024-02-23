#include <iostream>
#include "Person.h"
#include <vector>
using namespace std;
istream &read(istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}
ostream &print(ostream &os, Person &p)
{
    os << p.get_name() << " " << p.get_address();
    return os;
}

int main()
{
    vector<Person> pv;
    do {
        Person p(cin);
        pv.push_back(p);
    } while (cin);
    // 使用有两个形参的构造函数
    pv.push_back(Person("JackMa", "Hangzhou"));
    Person pe;  // 使用默认构造函数(成员数据均为空字符串)
    pv.push_back(pe);

    for (auto p : pv) {
        print(cout, p) << endl;
    }
    return 0;
}