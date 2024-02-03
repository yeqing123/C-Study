# include <iostream>
# include "Sales_item.h"

int main()
{
    Sales_item sum, item;
    // 输入第一个Sales_itme对象，存入sum变量
    if (std::cin >> sum) {
        // 连续输入多个对象，与sum相加并将结果赋给sum
        while (std::cin >> item) {
            sum += item;
        }
        // 输入结束后打印结果
        std::cout << "Sum is: " << sum << std::endl;
    }

    return 0; 
}