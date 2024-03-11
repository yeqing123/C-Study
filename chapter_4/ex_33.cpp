#include <iostream>

using namespace std;

int main()
{
    // 本程序验证自己对练习33中表达式的推断是否正确
    int x = 10, y = 20;
    bool someValue = true;
    someValue ? ++x, ++y : --x, --y;
    cout << "someValue = " << someValue << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;    // 因为条件为真，所以y的值会先加1，再减1，还是20
    
    someValue = false;
    someValue ? ++x, ++y : --x, --y;
    cout << "someValue = " << someValue << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}