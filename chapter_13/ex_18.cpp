#include <iostream>
#include <string>

using namespace std;

class Employee {
friend void f(const Employee&);
public:
    Employee() : my_cn(cn++) { }
    Employee(const string &s) : name(s), my_cn(cn++) { }
    Employee(const Employee &e) : name(e.name), my_cn(cn++) { }
    Employee operator=(const Employee&);
private:
    string name;
    int my_cn;
    static int cn;
};

int Employee::cn = 0;

Employee Employee::operator=(const Employee &e) {
    name = e.name;
    my_cn = cn++;
}

void f(const Employee &e)
{
    cout << "The name of employee: " << e.name 
         << ", certificate number: " << e.my_cn << endl;
}

int main()
{
    Employee a("Jack"), b("Tom"), c("Steven");
    cout << "using default constructor: " << endl;
    f(a);
    f(b);
    f(c);
    cout << endl;
    
    cout << "using copy constructor: " << endl;
    Employee d(a);
    a = b;
    b = c;
    f(a);
    f(b);
    f(c);
    f(d);
    return 0;
}
/*
* 我认为不需要定义拷贝控制成员，因为一个员工只需要有一个唯一的证号，
* 该证号应该是在构造该员工对象时生成的，对象的拷贝不应该再生成新的证号，
* 否则一个员工就会有多个证号，这与我们的期望并不一致。
*/