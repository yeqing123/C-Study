#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4};
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;   
        begin = v.insert(begin, 42);
        ++begin;
    }
    // 打印结果
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}