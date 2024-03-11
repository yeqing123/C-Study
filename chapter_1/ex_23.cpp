# include <iostream>
# include "Sales_item.h"
int main()
{
    Sales_item currItem, item;
    int cnt = 1;
    std::cout << "Please enter several sales records:(Ctrl+Z end)" << std::endl;
    // 输入第一条销售记录
    if (std::cin >> currItem) {
        while (std::cin >> item) {
            if (item.isbn() == currItem.isbn())
                cnt++;
            else {
                std::cout << "\"" << currItem.isbn() << "\"" << " occurs " 
                          << cnt << " times " << std::endl;
                currItem = item;
                cnt = 1;
            }
        }
        std::cout << "\"" << currItem.isbn() << "\"" << " occurs " 
                << cnt << " times " << std::endl;
    } else {
        std::cout << "No data!" << std::endl;
        return -1;
    }
    return 0;
}