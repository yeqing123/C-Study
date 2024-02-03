# include <iostream>
# include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << "Sum is: " << item1 + item2 << std::endl;

    return 0; 
}