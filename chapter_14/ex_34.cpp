#include <iostream>

using namespace std;

class IfThenElse {
public:
    IfThenElse() { }
    IfThenElse(bool bl, const string str1, const string str2) : b(bl), s1(str1), s2(str2) { }
    string operator()(bool bl, const string str1, const string str2) const {
        return bl ? str1 : str2;
    }
    string operator()() const {
        return b ? s1 : s2;
    }
private:
    bool b;
    string s1;
    string s2;
};

int main()
{
    int j = 2, i = 2;
    IfThenElse ie(i > j, "i > j", "i <= j");
    cout << ie() << endl;

    i = 20;
    cout << ie(i > 10, "i > 10", "j <= 10") << endl;
}