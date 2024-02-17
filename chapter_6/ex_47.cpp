#define OUTPUT_SIZE   //定义预处理变量，打开调试器(预处理变量的名字可以是任意的大写字母，但不能是NDEBUG否则预处理宏assert就会失效)
#include <iostream>
#include <vector>
#include "cassert"  // assert宏定义在cassert头文件中
using namespace std;
// 改写程序ex_33.cpp程序，使其每次调用函数时输出vector对象的大小
void recursive_output(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    // 如果已经定义了预处理变量，当前位置到#endif之间的语句就会被执行，否则不执行
    #ifdef OUTPUT_SIZE  
        // 检查vector对象是否为空，如果为空则输出提示信息并终止程序，否则什么也不做
        assert((end - beg) > 0 ); 
        // 输出vector对象的大小
        cout << "vector size: " << end - beg << endl;
    #endif
    if (beg == end) {
        return ;
    }
    cout << *beg << endl;
    // 注意第一个参数一定要用前置递增运算符，否则会无限递归输出vector对象的一个元素。
    // 或者干脆写成 beg+1 更保险
    recursive_output(++beg, end); 
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    recursive_output(v.cbegin(), v.cend());
    return 0;
}