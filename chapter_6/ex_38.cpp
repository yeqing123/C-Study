#include <iostream>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

// 修改书中206页的arrPtr函数，使其返回数组的引用
decltype(odd) &arrRef(int i)
{
    return (i % 2) ? odd : even;  // 数组的引用就是该数组的别名，因此直接返回数组的名称即可
}

int main()
{
    for (auto elem : arrRef(2)) {
        cout << elem << endl;
    }
    return 0;
}
