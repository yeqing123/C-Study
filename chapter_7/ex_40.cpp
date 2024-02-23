#include <iostream>
#include <vector>
#include "Vehicle.h"
using namespace std;
int main()
{
    vector<Vehicle> vehicles = {Vehicle("airplane", 75, 450)};
    Vehicle v;   // 定义一个空对象
    vehicles.push_back(v);
    
    cout << "Enter the data of a vehicle: ";
    char repeat = 'y';
    while (cin && repeat != 'n') {
        v = Vehicle(cin);
        vehicles.push_back(v);
        cout << "Do you continue? enter 'y' or 'n': ";
        cin >> repeat;
    }
    cout << endl;
    // 输出结果，如果遇到空对象，将其重新设置内容
    for (auto &v : vehicles) {
        if (v.isEmpty()) {
            cout << "There is a empty object. Please re-enter: ";
            v.reset(cin);
        }
        v.display(cout) <<endl;
    }
    return 0;
}