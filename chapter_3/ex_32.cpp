#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main()
{
    const int sz = 10;
    // 定义个int类型的数组，让每个元素的值与其所在下标相等
    int ia[sz];
    for (size_t index = 0; index < sz; ++index) {
        ia[index] = index;
    }
    // 将上述数组拷贝给另一个数组，数组拷贝不可使用赋值运算符，只能逐个元素进行拷贝
    int ia2[sz];
    for (size_t index = 0; index < sz; ++index) {
        ia2[index] = ia[index];
    }
    // 打印拷贝后的结果
    cout << "ia: " << endl;
    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;
    cout << "ia2: " << endl;
    for (auto i : ia2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "----Using 'vector' to implement same function:----" << endl;
    // 使用vector实现同样的功能
    vector<int> iv, iv2;
    for (unsigned n = 0; n < sz; ++n) {
        iv.push_back(n);
    }
    // 将iv拷贝给iv2，可以直接使用赋值运算符
    iv2 = iv;
    iv[0] = 3;  //iv和iv2各自都拥有独立的元素对象，互补影响
    // 打印结果
    cout << "iv: " << endl;
    for (auto i : iv) {
        cout << i << " ";
    }
    cout << endl;
    cout << "iv2: " << endl;
    for (auto i : iv2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}