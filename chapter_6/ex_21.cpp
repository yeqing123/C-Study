#include <iostream>
#include <ctime>

using namespace std;
// compare_val函数比较两个整数的大小，第二个形参也可以是一个数组，该指针指向了数组的首元素
int compare_val(const int a, const int* p) 
{
    return a > *p ? a : *p;
}

int main()
{
    int a = 20, b = 12;
    cout << "a = " << a << " b = " << b << endl;
    cout << "Digit of larger is: " << compare_val(a, &b) << endl;
    // 打印一个分割线
    cout << "-------------------------------------------" << endl;
    // 第二个参数也可以是数组
    srand((unsigned)time(NULL));
    int arr[10];
    for (auto &i : arr) {
        i = rand() % 10;        // 生成10个0~10之间的随机整数，存入数组
    }
    int c;
    cout << "Enter a integer between 0 and 10: ";
    cin >> c;
    // 比较输入的整数和数组首元素的大小
    cout << "The larger of the number you entered and the first element of the array is: " 
         << compare_val(c, arr) << endl;
    // 打印数组所有元素
    cout << "All of the elements of the array:" << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}