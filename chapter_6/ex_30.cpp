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
            return ;   // 错误：没有返回值
        }
    }
    // 错误：控制流可能尚未返回任何值就结束了函数的执行
    // 编译器可能检查不出来这一错误
}
/*
* 在Visul Studio Code 1.86.2编译器中，首先对程序第15行进行了报错。
* 当我修复了这一错误后，编译去就不在报错了。并且当出现结果为ture时（即一个字符串是另一个的子区间时），
* 编译器还自动在函数最后加上了隐藏的return true语句。
*/

int main()
{
    string str1("same"), str2("same string");
    cout << "Whether strings str1 and str2 exist subrange of one is the other: " 
         << (str_subrange(str1, str2) ? "true" : "false") << endl;
    return 0;
}