#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;

// 已经在Vehicle类型中添加了转换目标是bool的类型转换运算符
// 本程序验证是否正确
int main()
{
    Vehicle veh1("bicycle", 2, 15), veh2("bus", 30, 0), veh3;
    vector<Vehicle> vs{veh1, veh2, veh3};

    // 分别判断veh1和veh2是否为空
    for (auto v : vs) {
        if (v) {
            cout << v << endl;
        } else {
            cout << "Empty instance!" << endl;
        }
    }
}