#include <iostream>
using namespace std;
/*
* 参考书中6.2.4节介绍的内容，定义不同版本的print函数，
* 使每个函数都可以传入int i = 0, j[2] = {0, 1}，两个实参。
*/

// 想要同时传入i,j两个实参，似乎只能显示传递一个表示数组大小的形参
void print(const int arr[], size_t dimension)
{
    for (size_t i = 0; i < dimension; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i, 1);
    print(j, end(j) - begin(j));
    return 0;
}