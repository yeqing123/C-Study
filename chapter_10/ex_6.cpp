#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> lit{1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_n(lit.begin(), lit.size(), 0);     // 将序列中所有的元素都改为0
    for (auto i : lit) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}