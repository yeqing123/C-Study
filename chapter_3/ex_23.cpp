#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    srand((unsigned)time(NULL));        // 定义生成随机数的种子
    vector<int> intVec;  
    for (int i = 0; i < 10; ++i) {
        intVec.push_back(rand() % 100);  // 生成10个100以内的随机数
    }
    // 输出元素时可以使用cbegin和cend迭代器
    cout << "Before the modification:" << endl;
    for (auto it = intVec.cbegin(); it != intVec.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // 修改元素值时使用普通迭代器
    for (auto it = intVec.begin(); it != intVec.end(); ++it) {
        *it *= 2;
    }
    // 输出修改后的结果
    cout << "After the modification:" << endl;
    for (auto it = intVec.cbegin(); it != intVec.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}