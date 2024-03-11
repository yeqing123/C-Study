#include <iostream>
#include "Sales_data.h"

string make_plural(int count, const string &word, const string &s) 
{
    return (count > 1) ? word + s : word;
}

int main()    
{
    Sales_data total;                 // 保存交易记录
    int bookSum = 0, infoSum = 0;     // 统计信息数量

    // 输入第一条交易记录
    if (std::cin >> total) {
        ++infoSum;
        ++bookSum;
        Sales_data data;
        // 连续输入多条交易记录
        while (std::cin >> data) {
            ++infoSum;                 // 统计交易记录的数量
            // 累计相同书的销售记录
            if (compareIsbn(total, data)) {
                total += data;
            } else {
                // 打印上一本书的销售记录
                std::cout << total << endl;
                total = data;         // 更新total
                ++bookSum;            // 统计书本数量
            }
        }
        // 打印最后一本书的交易记录
        std::cout << total << endl;
        // 打印最后的汇总数据
        std::cout << "There are " << bookSum << " " << make_plural(bookSum, "book", "s")
                  << " and " << infoSum << " transaction " << make_plural(infoSum, "record", "s")
                  << endl;
    } else {
        cerr << "No data!?" << endl;
        exit(1);
    }
    return 0;
}