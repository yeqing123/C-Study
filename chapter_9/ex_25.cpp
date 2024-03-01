#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    // elem1和elem2皆为尾后迭代器时，不删除任何元素，返回值还是尾后迭代器
    std::vector<int>::iterator elem1 = v.end();
    std::vector<int>::iterator elem2 = v.end();
    std::cout << "elem1 and elem2 are \"off-the-end\":" << std::endl;
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    // elem1和elem2相等，不删除任何元素，返回值还是elem1和elem2所指位置的迭代器
    elem1 = v.begin() + 1;
    elem2 = v.begin() + 1;
    std::cout << "elem1 == elem2: " << std::endl;
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 只有elem2为尾后迭代器，删除从elem1之后的所有元素（包含elem1）
    // 此时迭代器elem1指向第二个元素，即整数2
    elem2 = v.end();
    v.erase(elem1, elem2);
    std::cout << "Only elem2 is \"off-the-end\":" << std::endl;
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}