#include <iostream>
#include <vector>
// 查看自己的c++标准库实现中，vector是如何增长的
int main()
{
    std::vector<std::string> vec;
    auto prev = vec.capacity();
    auto curr = vec.capacity();
    while (true) {
        vec.push_back("apple");                // 向vec中插入字符串"apple"
        if (vec.size() == vec.capacity()) {    // 当元素数量等于当前容量时，打印相关信息
            std::cout << "vector size:" << vec.size()
              << "\tvector capacity:" << vec.capacity() << std::endl;
        }
    }
    return 0;
}