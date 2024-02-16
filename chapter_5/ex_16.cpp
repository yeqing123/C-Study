#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
// 根据for语句和while语句的特点，各编写一段程序
int main()
{
    //使用for循环，计算1到10直接所有整数的乘积
    long product = 1;
    for (int i = 1; i <= 10; i++) {
        product *= i;
    }
    cout << "The product of all integers from 1 to 10: " << product << endl;

    // 使用while循环，从输入中读取字符串保存到vector对象中
    string s;
    vector<string> v;
    while (cin >> s) {
        v.push_back(s);
    }
    cout << "output vector:" << endl;
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;


    // 两种循环风格互相改写，看看哪个好
    long product = 1;
    int i = 1;
    while (i <= 10) {
        product *= i;
        i++;
    }
    cout << "The product of all integers from 1 to 10: " << product << endl;
    
    string s;
    vector<string> v;
    for (; cin >> s; v.push_back(s)) {
        /* statement is empty */
    }
    cout << "Output vector: " << endl;
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}