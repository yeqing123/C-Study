#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    auto iter = v.begin();
    while (iter != v.end()) {
        if (*iter % 2) {
            iter = v.insert(iter, *iter);
        }
        ++iter;
    }
    // 打印结果
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}