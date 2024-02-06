#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    // 读入一组整数，并存入一个vector对象中
    vector<int> intvec;
    int integer;
    while (cin >> integer) {
        intvec.push_back(integer);
    }
    // 输出vector对象中的每个元素
    for (auto i : intvec) {
        cout << i << endl;
    }
    return 0;
}