#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    // 编写代码，验证如何用一个list<ing>初始化一个vector<double>容器
    // 以及如何从一个vector<int>初始化一个vector<double>容器
    // 因为类型不同，我们只能使用迭代器来初始化
    list<int> original_li{1, 3, 5, 6, 7, 8};
    vector<double> target_vec1(original_li.begin(), original_li.end());

    vector<int> original_vec{3, 4, 5, 6, 7, 8};
    vector<double> target_vec2(original_vec.begin(), original_vec.end());

    // 打印结果
    for (auto elem : target_vec1) {
        cout << elem << " ";
    }
    cout << endl;
    for (auto elem : target_vec2) {
        cout << elem << " ";
    }
    cout << endl;
}