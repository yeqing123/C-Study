#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data sd;
    cin >> sd;
    string s = "Show data:\n";
    cout << s.append(sd) << endl;  // 将Sales_data类型隐式转换为string类型，返回sd的所有信息
    cout << sd + 10.5 << endl;     // 隐式转换为double类型，返回的是units_sold * sellingprice，即总销售额
    return 0;
}