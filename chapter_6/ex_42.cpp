#include <iostream>
using namespace std;
// 当ctr的值大于0时，返回word的复数形式（为第二个字符串形参指定默认实参's'）
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << "Word \"success\"" << endl;
    cout << "\tprototype: " << make_plural(1, "success") << endl;
    cout << "\tplural: " << make_plural(2, "success", "es") << endl;

    cout << "Word \"failure\"" << endl;
    cout << "\tprototype: " << make_plural(1, "failure") << endl;
    cout << "\tplural: " << make_plural(2, "failure");

    return 0;
}