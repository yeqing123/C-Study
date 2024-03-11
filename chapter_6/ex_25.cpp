#include <iostream>
#include <string>
using namespace std;
/*
* main函数包含两个参数，argv是一个数组，它的元素是指向C风格字符串的指针；
* argc表示数组中字符串的数量。
*/
int main(int argc, char ** argv)
{
    string str;  
    for (size_t i = 0; i != argc; ++ i) {
        str += argv[i];
    }
    cout << str << endl;
    return 0;
}