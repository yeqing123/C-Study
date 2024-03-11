#include <iostream>
using namespace std;
// 因为含有不正确的返回值，所以这段代码无法通过编译
bool str_subrange(const string &str1, const string &str2)
{
    // 大小相同：此时用普通的相等性判断结果作为返回值
    if (str1.size() == str2.size()) {
        return str1 == str2;   // 正确：==运算符返回布尔值
    }
    // 得到较短string对象的大小
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    // 检查两个string对象的对应字符是否相等，以较短的字符串长度为限
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i]) {
            return false;   // 错误：没有返回值
        }
    }
    // 这里还存在一个错误，当for循环执行完毕后，应该在最后还有一个return true
}
/*
* 在Visul Studio Code 1.86.2编译器中，首先对程序第15行进行了报错，
* 但遗憾的是编译器没有发现另外一个错误。当出现for循环执行完毕时（即一个字符串是另一个的子区间时），
* 函数依然返回了true。也许是编译器自动在最后加上了语句return true。
*/

int main()
{
    string str1("same"), str2("same string");
    cout << "Are there substrings in two strings where one is the other?\n" 
         << (str_subrange(str1, str2) ? "true" : "false") << endl;
    return 0;
}