# include <iostream>
# include "Sales_item.h"
int main()
{
    Sales_item currItem, item;
    int cnt = 1;
    // 输入第一条销售记录
    if (std::cin >> currItem) {
        while (std::cin >> item) {
            if (item.isbn() == currItem.isbn())
                cnt++;
            else {
                std::cout << "\"" << currItem << "\"" << " occurs " 
                          << cnt << " times " << std::endl;
                currItem = item;
                cnt = 1;
            }
        }
    }
    std::cout << "\"" << currItem << "\"" << " occurs " 
              << cnt << " times " << std::endl;
    return 0;
}