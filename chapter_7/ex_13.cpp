#include <iostream>
#include "Sales_data_v3.h"
using namespace std;
// 使用istream构造函数重写第229页的程序
int main()
{
    Sales_data_v3 total(cin);  //  创建第一个对象
    if (cin) {
        //因为要先在构造器中使用istream，所以使用do...while
        // 并且输入流是在构造器中结束的，因此最后一条记录是个空对象，无须在循环结束后打印出来。
        do {   
            Sales_data_v3 trans(cin);  
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }while (cin);  
        // 最后一条无效的空记录无须再打印，真正的最后一本书的记录已在循环结束前打印了。
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}