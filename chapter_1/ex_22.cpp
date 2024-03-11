# include <iostream>
# include "Sales_item.h"
int main()
{
    Sales_item sum, item;
    // 输入第一个Sales_itme对象，存入sum变量
    std::cout << "Please enter several ISBN identical sales records: " << std::endl;
    if (std::cin >> sum) {
        // 连续输入多个对象，与sum相加并将结果赋给sum
        while (std::cin >> item) {
            if (compareIsbn(sum, item)) { // 判断ISBN是否相同
                sum += item;
            } else {  // ISBN不同
                std::cout << "ISBN difference!" << std::endl;
            }
        }
        // 输入结束后打印结果
        std::cout << "Summary of information(ISBN, quantity sold, sales and averate price): \n"
                  << sum << std::endl;
    } else {
        std::cout << "No data!" << std::endl;
        return -1;
    }

    return 0; 
}