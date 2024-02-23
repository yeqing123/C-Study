#include <iostream>
#include "Sales_data_del.h"
using namespace std;
int main()
{
    // 以各种方式创建Sales_data_del，观察并思考构造函数的调用顺序
    cout << "Sales_data_del sd1: " << endl;
    Sales_data_del sd1;
    cout << "\nSales_data_del sd2(\"ABCD-EF\"): " << endl;
    Sales_data_del sd2("ABCD-EF");
    cout << "\nSales_data_del sd3(\"abcd-ef\", 2, 10): " << endl;
    Sales_data_del sd3("abcd-ef", 2, 10);
    cout << "\nSales_data_del sd4(cin): " << endl;
    Sales_data_del sd4(cin);

    return 0;
}