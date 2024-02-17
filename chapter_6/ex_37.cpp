#include <iostream>
using namespace std;
/*
* 定义三个函数，它们均返回一个包含10个string对象的数组的引用。
* 它们分别使用类型别名、尾置返回类型、decltype关键字。
*/
string sarr[10] = {
    "word_0", "word_1", "word_2", "word_3", "word_4", 
    "word_5", "word_6", "word_7", "word_8", "word_9"};


// 声明函数返回的类型别名
typedef string (&rsaT)[10];  // rsaT是一个别名，它表示类型是一个包含10个string对象的数组的引用
using rsaT = string(&)[10];    // rsaT的等价声明


// 使用类型别名
rsaT func_1()
{
    return sarr;
}

// 使用尾置返回类型
auto func_2() -> string(&)[10] 
{
    return sarr;
}

// 使用decltype关键字
decltype(sarr) &func_3()
{
    return sarr;
}
int main()
{
    // 调用完函数后直接输出其返回的数组的元素，以验证返回值的类型是数组的引用而非指针
    for (auto s : func_1()) {
        cout << s << " ";
    }
    cout << endl;

    for (auto s : func_2()) {
       cout << s << " ";
    }
    cout << endl;

    for (auto s : func_3()) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}