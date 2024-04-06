#include <iostream>
#include <vector>
#include "String.h"

using namespace std;

int main()
{
    vector<String> vec;
     vec.reserve(3);        // 当每次添加元素时，有可能因为内存不够用分配新内存，
                              // 然后将元素从旧内存移动到新内存，因此会多次执行移动操作。
                              // 如果预设vec的大小，则可以消除多余的移动操作。
    String s1("hello"), s2("world");
    cout << "---------------" << endl;
    vec.push_back(s1);        // 使用拷贝操作
    vec.push_back(std::move(s2)); // 指定使用移动操作
    vec.push_back("C++");     // 这个最后特点：前两个都是指定了操作方式，唯有这个，
                              // 编译器自动匹配移动构造函数来完成元素的添加操作。
}