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
    cout << "Enter several integers(press Ctr+Z to end): " << endl;
    while (cin >> integer) {
        intvec.push_back(integer);
    }
    // 输出vector对象中的每个元素
    if (intvec.size() != 0) {
        cout << "Display all the elements of the container: " << endl;
        for (auto i : intvec) {
            cout << i << endl;
        }
    } else {
        cout << "The container is empty!" << endl;
    }
    return 0;
}