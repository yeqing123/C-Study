#include <iostream>
#include <vector>
using namespace std;
// 声明一个函数
int func(int, int);
// 声明一个vector对象，令其元素指向func函数
vector<decltype(func)*> vec;   // 因为decltype的结果是函数类型，所以只有在结果后面加上*才是指针类型
/* 
* 注意：元素是指向func函数类型的指针，而不是只指向func函数，
* 因此vector可以定义成：vector<int (*) (int, int)> vec;
*/

// 定义四个函数，分别对两个int参数执行加、减、乘、除运算
int add(int i1, int i2)
{
    return i1 + i2;
}

int subtract(int i1, int i2)
{
    return i1 - i2;
}

int multiply(int i1, int i2)
{
    return i1 * i2;
}

int divide(int i1, int i2)
{
    return i1 / i2;
}

int main()
{
    // 将指向执行加、减、乘、除四个函数的指针保存到vector对象中。
    // 它们的函数名虽然不同，但是所有的元素类型都是一样的，都是 int (*) (int, int)类型的。
    vec.push_back(add);   // 可以直接把函数所谓实参使用，它会自动转换成指针
    vec.push_back(subtract);
    vec.push_back(multiply);
    vec.push_back(divide);
    // 调用每个元素指向的函数，并输出结果
    for (auto pf : vec) {
        // 可以直接使用指针调用函数，而无须解引用指针
        cout << pf(6, 2) << endl;
    }
    return 0;
}