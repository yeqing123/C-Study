#include <iostream>
#include <string>
#include "Sales_data.h"  // 将Sales_data类放在了Sales_data.h头文件里
int main()    // 程序的其他部分与练习41相同
{
    Sales_data sum;
    double price;  // 每本书的单价
    int cnt = 1;   // 记录每本书有几条销售记录

    // 输入第一条数据
    if (std::cin >> sum.bookName >> price >> sum.sold_quantity) {
        // 计算总销售额
        sum.sold_amount = sum.sold_quantity * price;
        Sales_data data;
        // 连续输入多条数据
        while (std::cin >> data.bookName >> price >> data.sold_quantity) {
            // 计算每条数据的总销售额
            data.sold_amount = data.sold_quantity * price;
            if (sum.bookName == data.bookName) {
                // 累加总销售量和总销售额到sum中
                sum.sold_quantity += data.sold_quantity;
                sum.sold_amount += data.sold_amount;
                cnt++;
            } else {
                // 如果总销售额不为零，则打印结果
                if (sum.sold_quantity != 0) {
                    sum.average_price = sum.sold_amount / sum.sold_quantity;
                    std::cout << "Sales data: " << sum.bookName << " " << sum.sold_quantity
                                << " " << sum.sold_amount << " " << sum.average_price << std::endl;
                    
                } else {
                    std::cerr << sum.bookName << " sold quantity is 0!" << std::endl; // 如果销售量为0，则输出错误提示
                }
                // 打印每本书输入记录的数量
                std::cout << sum.bookName << " occurs " << cnt << " times.\n" << std::endl;
                sum = data;  // 更新sum
                cnt = 1;     // 重置cnt
            }
        }
        // 打印最后一组数据的结果
        if (sum.sold_quantity != 0) {
                sum.average_price = sum.sold_amount / sum.sold_quantity;
                std::cout << "Sales data: " << sum.bookName << " " << sum.sold_quantity
                            << " " << sum.sold_amount << " " << sum.average_price << std::endl;
        } else {
            std::cerr << sum.bookName << " sold quantity is 0!" << std::endl; // 如果销售量为0，则输出错误提示
        }
        // 打印每本书输入记录的数量
        std::cout << sum.bookName << " occurs " << cnt << " times.\n" << std::endl;
    }
    return 0;
}