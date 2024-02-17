#include "Chapter6.h"

/*
 * 定义头文件Chapter6.h中声明的fact函数，
 * 如果函数的定义与头文件中的声明不服，编译器会报错。
*/ 
int fact(int val)
{
    int result = 1;   // 保存计算结果
    while (val > 1) {
        result *= val--;
    }
    return result;
}