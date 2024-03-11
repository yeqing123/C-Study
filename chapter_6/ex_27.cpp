#include <iostream>
using namespace std;
// 函数sum计算initializer_list<int>类型的列表元素的和
int sum(initializer_list<int> lst)
{
    int sum = 0;
    for (auto val : lst) {
        sum += val;
    }
    return sum;
}

int main()
{
    // 必须使用列表初始化方式构建initailizer_list对象
    cout << "The sum of \"5, 4, 9, 4, 8, 10, 24\" is: "
         << sum({5, 4, 9, 4, 8, 10, 24}) << endl;
    cout << "The sum of \"3, 5, 6, 4, 9, 7, 2\" is: "
         << sum({3, 5, 6, 4, 9, 7, 2}) << endl;
    return 0;
}