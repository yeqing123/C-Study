#include <iostream>
#include <vector>

using namespace std;
// 本程序验证练习7（b）的答案
int main()
{
    vector<int> vec;
    vec.reserve(10);    // 只是分配了足够的内存空间，但是容器依然为空
    fill_n(vec.begin(), vec.size(), 0);
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    cout << vec.size() << endl;  // 容器依然为空
    return 0;
}