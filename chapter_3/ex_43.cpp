#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    // 使用三个不同的版本，输出ia的元素
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // 版本1：使用范围for语句管理迭代过程
    cout << "Version 1: Use range for statement" << endl;
    for (int (&row)[4] : ia) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    // 版本2：使用下标运算符
    cout << "Version 2: Use subscript operator" << endl;
    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    // 版本3：使用指针
    cout << "Version 3: Use pointers" << endl;
    for (int (*rp)[4] = ia; rp != ia + 3; rp++) {
        for (int *cp = *rp; cp != *rp + 4; cp++) {
            cout << *cp << " ";
        }
        cout << endl;
    }
    return 0;
}