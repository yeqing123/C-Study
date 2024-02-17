#include <iostream>
using namespace std;
// 函数sum计算initializer_list<int>类型的列表元素的和
int sum(initializer_list<int> lst)
{
    int sum = 0;
    for (auto elem : lst) {
        sum += elem;
    }
    return sum;
}

int main()
{
    cout << "The result of sum({5, 4, 9, 4, 8, 10, 24}) is: "
         << sum({5, 4, 9, 4, 8, 10, 24}) << endl;
    return 0;
}