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
    // 当第一个实参不大于1时，不会添加任何后缀
    cout << "\tprototype: " << make_plural(1, "success") << endl;
    // 指定了第三个参数
    cout << "\tplural: " << make_plural(2, "success", "es") << endl;

    cout << "Word \"failure\"" << endl;
    cout << "\tprototype: " << make_plural(1, "failure") << endl;
    // 使用第三个形参的默认值s
    cout << "\tplural: " << make_plural(2, "failure");

    return 0;
}