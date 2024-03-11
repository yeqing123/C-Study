#include <iostream>
#include <string>
using namespace std;
// 函数hasUpper判断传入的string对象中是否包含大写字母
// 形参是常量引用，因为无须修改实参内容，使用常量引用传入的实参类型可以不受限制
bool hasUpper(const string &s)  
{
    for (char c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// 函数changeToLower会将传入的string对象全部改写成小写字母
// 因为要修改实参内容，所以形参类型不能是常量引用
void changeToLower(string &s) {
    for (char &c : s) {  // c也要定义成引用类型，否则修改的就只是函数中的局部变量，而非实参中的字符
        c = tolower(c);
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);   // 从标准输入中读取一行字符
    // 调用hasUpper函数，判断str中是否保存大写字母
    if(hasUpper(str)) {
        cout << "This string contains upper case letters." << endl;
    } else {
        cout << "This string does not contain upper case letters." << endl;
    }
    // 调用toLower函数，将str全部修改为小写字母
    changeToLower(str);  
    cout << "Change string to lower case letters: " << str << endl;
    return 0;
}