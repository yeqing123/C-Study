#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iv;
    list<int> il;
    iv.assign(begin(ia), end(ia));
    il.assign(begin(ia), end(ia));

    vector<int>::iterator vit = iv.begin();
    while (vit != iv.end()) {
        if (*vit != 0 && !(*vit % 2)) {
            vit = iv.erase(vit);  // 删除vector中的偶数
        } else {
            ++vit;
        }
    }
    list<int>::iterator lit = il.begin();
    while (lit != il.end()) {
        if (*lit % 2) {
            lit = il.erase(lit);  // 删除list中的奇数
        } else {
            ++lit;
        }
    }
    // 打印结果
    cout << "All even numbers are removed in the vector: ";
    for (auto i : iv) {
        cout << i << " ";
    }
    cout << endl;

    cout << "All odd numbers are removed in the list: ";
    for (auto i : il) {
        cout << i << " ";
    }
    cout << endl;
}