#include <iostream>
#include <list>
#include <vector>
// 将一个list中的char *指针元素赋值非一个vector中的string
int main()
{
    std::list<char*> li{"hello", "world", "c++"};
    std::vector<std::string> vec;
    vec.assign(li.begin(), li.end());
    // 打印结果
    for (auto s : vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}