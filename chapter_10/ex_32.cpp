#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iterator>
#include <functional>
#include "Sales_data.h"

using namespace std;
using namespace std::placeholders;

int main()
{
    ifstream in("Sales_data.txt");
    if (!in) {                                            // 文件打开失败
        cerr << "Opening file faild!" << endl;
        exit(1);
    }
    istream_iterator<Sales_data> in_iter(in), eof;       // 创建输入流迭代器
    ostream_iterator<Sales_data> out_iter(cout, "\n");   // 创建输出流迭代器，每次输出的数据都以换行符结尾
    vector<Sales_data> vec;
   
    copy(in_iter, eof, inserter(vec, vec.begin()));      // 使用插入迭代器，从输入流中读取数据保存到vec容器中

    sort(vec.begin(), vec.end());                        // 因为我们在Sales_data类中已经将<运算符重新定义为
                                                         // 对ISBN进行比较，所以无需再给sort传入第三个参数，
                                                         // 就可以依据ISBN的大小对销售记录进行排序，从而将ISBN相同的记录排列在一起。
                                                         // 注意：不能使用compareIsbn作为第三个参数，因为compareIsbn是对ISBN是否相等
                                                         // 进行判断，而sort默认基于<运算符进行排序，如果使用compareIsbn将无法实现排序。
    cout << "After sorted transaction records:" << endl;
    copy(vec.cbegin(), vec.cend(), out_iter);            // 向控制台输出排序结果

    cout << "Summarized results:" << endl;
    auto begin = vec.cbegin();
    while (begin != vec.cend()) {
        Sales_data total = *begin;
        auto end = find_if(begin + 1, vec.cend(),        // 使用lambda，调用find_if确定序列中相同ISBN范围的结束位置
                            [total](const Sales_data& item) 
                            { return total.isbn() != item.isbn(); });
        total = accumulate(begin + 1, end, total);       // 对相同ISBN的记录进行汇总
        out_iter = total;                                // 输出汇总信息
        begin = end;                                     // 更新到下一条ISBN
    }
    return 0;
}