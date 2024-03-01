#include <iostream>
#include <vector>
// 判断两个vector<int>是否相等
int main()
{
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 4};

    if (vec1 == vec2) {
        std::cout << "vec1 equals vec2." << std::endl;
    } else {
        std::cout << "vec1 is not equal to vec2." << std::endl;
    }
    return 0;
}