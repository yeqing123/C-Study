#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 使用at、下标运算符、front和begin提取vector中的第一个元素
    vector<int> iv{2, 4, 5, 7, 3, 8};
    auto val1 = iv.at(0);
    auto val2 = iv[0];
    auto val3 = iv.front();
    auto val4 = *iv.begin();

    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;
    cout << "val3 = " << val3 << endl;
    cout << "val4 = " << val4 << endl;
    // 当vector为空时，只有成员函数at会抛出一个out_of_range异常，
    // 其余访问元素的行为都将是未定义的。

    return 0;
}