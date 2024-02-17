#include <iostream>
#include <string>
using namespace std;
// 函数has_capital判断传入的string对象中是否包含大写字母
// 形参是常量引用，因为无须修改实参内容，使用常量引用传入的实参类型可以bu'shou'xian不受限制
bool has_capital(const string& s)  
{
    for (char c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// 函数tolower会将传入的string对象全部改写成小写字母
// 因为要修改实参内容，所以形参类型不能是常量引用
void tolower(string& s) {
    for (char &c : s) {  // c也要定义成引用类型，否则修改的就只是函数中的局部变量，而非实参中的字符
        c = tolower(c);
    }
}

int main()
{
    string s1("hello world!"), s2("I Am Learning C++");
    // 调用has_capital函数，判断s1中是否保存大写字母
    string msg = has_capital(s1) ? "s1 contains capitals." : "s1 does not contain capitals!";
    cout << msg << endl;

    tolower(s2);  // 调用tolower函数，将s2全部修改为小写字母
    cout << "Change s2 to lower case letters: " << s2 << endl;
    return 0;
}