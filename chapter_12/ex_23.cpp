#include <iostream>
#include <cstring>  // <cstring>是C++版本的C 标准库头文件，其中定义了一系列 C 语言风格的字符串操作函数

using namespace std;

int main()
{
    const char *c1 = "hello ";
    const char *c2 = "world";
    // 分配动态数组，维度大小为两个字符串的长度之和加1，用于保存最后的'\0'
    char *pca = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(pca, c1);  // 拷贝第一个字符串
    strcat(pca, c2);  // 连接第二个字符串
    cout << pca << endl;

    string s1 = "HELLO ";
    string s2 = "WORLD";
    // string的成员函数c_str，返回一个指向正规C字符串的指针常量，
    // 然后将其拷贝到动态数组中
    strcpy(pca, (s1+s2).c_str());
    cout << pca << endl;
    // 释放内存
    delete [] pca;

    return 0;
}