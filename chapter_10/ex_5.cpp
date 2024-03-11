#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
// 为了验证练习5，我们使用C风格的字符串来调用equal，看看会发生什么
int main()
{
    char *r1[] = {"hello", "world", "!"};  // 定义包含C风格字符串的数组
    char *r2[] = {strdup(r1[0]), strdup(r1[1]), strdup(r1[2])};  // 虽然r2中包含了r1中字符串的拷贝，但是其指针所指向的地址是不同的
    char *r3[] = {r1[0], r1[1], r1[2]};               // r1和r3中包含的指针都指向相同的地址

    // equal比较的是字符指针的值
    cout << equal(begin(r1), end(r1), r2) << endl;    
    cout << equal(begin(r1), end(r1), r3) << endl;
}