#include <iostream>
using namespace std;
/*
* 定义三个函数，它们均返回一个包含10个string对象的数组的引用。
* 它们分别使用类型别名、尾置返回类型、decltype关键字。
*/
string sarr[10] = {
    "word_0", "word_1", "word_2", "word_3", "word_4", 
    "word_5", "word_6", "word_7", "word_8", "word_9"};


// 使用类型别名
typedef string arr[10];    // 使用typedef定义维度为10，元素类型为string的数组的类型别名arr
using arr = string [10];    // 也可以使用using定义同样的类型别名


// 使用类型别名
arr &func_1()
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
    // 调用函数，并打印数组元素
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