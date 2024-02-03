# include <iostream>
# include "Sales_item.h"
int main()
{
    Sales_item total, trans;
    // 输入第一条销售记录
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;  // 更新销售记录
            } else {
                // 打印前一本数的结果
                std::cout << total << std::endl;
                total = trans;
            }
        }
        // 打印所有一本数的结果
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}