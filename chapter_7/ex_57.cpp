#include <iostream>
#include <string>
using namespace std;
// 定义我自己的Account类
class Account {
public:
    Account() = default;
    Account(string o, string numb, double amo = 0) : owner(o), acc_number(numb), amount(amo) {}
    double rate() { return interestRate; }
    // 静态成员函数的定义既可以在类的内部也可以在类的外部
    static void set_rate(double newRate) { interestRate = newRate; }
    double caculate() const { return amount * interestRate; }
    ostream &show(ostream&) const;
private:
    string owner;
    string acc_number;
    double amount;
    static double interestRate;   // 这里仅仅是声明了一个静态成员，其定义应该在类的外面
};
// 静态成员的定义与全局变量类似
double Account::interestRate = 3.5;

ostream &Account::show(ostream &os) const {
    os << "owner: " << owner << "\n\taccount number: " << acc_number
       << "\n\tamount: "  << amount << "\n\trate: " << interestRate 
       << "\n\taggregate: " << caculate();
    return os;
}
int main()
{
    Account my_account("yeqing", "258796431", 10000);
    Account wife_acc("liusha", "13655798423", 9999);
    my_account.show(cout) << endl;
    wife_acc.show(cout) << endl;

    cout << "\n----modify interest rate----" << endl;
    my_account.set_rate(1.5);  // 因为静态成员interestRate是所有对象共享的，所以修改一个对象，其他对象都会受影响
    my_account.show(cout) << endl;
    wife_acc.show(cout) << endl;
    return 0;
}

