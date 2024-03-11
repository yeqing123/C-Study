#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// 分别使用using和typedef来声明的别名，代替循环控制变量的类型
int main()
{
    // 使用三个不同的版本，输出ia的元素
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    
    // 声明别名
    using int_array = int[4];
    using array_pointer = int(*)[4];  // 从内向外解读，首先声明别名是一个指针，然后声明该指针指向的是有4个元素的数组，最后声明元素的类型是整型
    typedef int integer;
    
    // 版本1：使用范围for语句管理迭代过程
    cout << "Version 1: Use range for statement" << endl;
    for (int_array &row : ia) {
        for (integer col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    // 版本2：使用下标运算符
    cout << "Version 2: Use subscript operator" << endl;
    for (integer i = 0; i < 3; i++) {
        for (integer j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    
    // 版本3：使用指针
    cout << "Version 3: Use pointers" << endl;
    for (array_pointer rp = ia; rp != ia + 3; rp++) {
        for (integer *cp = *rp; cp != *rp + 4; cp++) {
            cout << *cp << " ";
        }
        cout << endl;
    }
    return 0;
}