#include <fstream>
#include "../chapter_7/Sales_data_v3.h"  // 我们使用第7章中定义的Sales_data_v3类，并且不做任何修改
using namespace std;
// 修改上一个练习，从文件sales_data.txt中读取数据，
// 将结果写入到一个文件中，将指定的文件名传递给main的第二个参数。
// 首先，运行命令：g++ ex_7.cpp -o ex_7，编译程序生成可执行文件ex_7.exe
// 然后运行命令：ex_7 sales_data.txt data_total.txt 执行可执行文件，并向main函数分别传入要读取的文件名和要写入的文件名
int main(int argv, char **argc) {
    // argc[0]是程序名，所以跳过
    char **rfp = argc + 1;   // 指向要读取的文件名
    char **ofp = argc + 2;   // 指向要写入的文件名f
    ifstream input(*rfp);  // 创建输入流对象并关联到文件
    Sales_data_v3 total;
    if (read(input, total)) {
        ofstream output(*ofp, ofstream::app); // 创建输出流对象，并设置模式为追加到文件尾部，如果文件不存在系统会自动创建一个
        Sales_data_v3 trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) << endl;  // 将结果写入文件末尾
                total = trans;
            }
        }
        print(output, total) << endl;  // 将最后一条结果写入文件末尾
    } else {
        cerr << "Failed to open file \"" << *rfp << "\"!" << endl;
    }
    return 0;
}