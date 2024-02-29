#include <fstream>
#include <iostream>
#include "../chapter_7/Sales_data_v3.h"  // 我们使用第7章中定义的Sales_data_v3类，并且不做任何修改
using namespace std;
// 通过命令：g++ ex_6.cpp -o ex_6，将本文件编译成ex_6.exe的可执行文件
// 然后通过命令：ex_6 sales_data.txt sales_data_2.txt，执行可执行文件并向main函数传递两个文件名，并且依次从文件中读取交易记录
int main(int argv, char **argc) {
    // argc[0]是程序名，所以跳过
    for (auto p = argc + 1; p != argv + argc; ++p) {
        Sales_data_v3 total;
        ifstream input(*p);  // 打开文件名关联到输入流，程序的剩余部分与书本229页完全相同
        if (read(input, total)) {
            Sales_data_v3 trans;
            while (read(input, trans)) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    print(cout, total) << endl;
                    total = trans;
                }
            }
            print(cout, total) << endl;
        } else {
            cerr << "Failed to open file \"" << *p << "\"!" << endl;
        }
    }
    return 0;
}