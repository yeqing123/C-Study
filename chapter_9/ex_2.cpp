#include <list>
#include <deque>
#include <iostream>
int main()
{
    // 定义一个list对象，其元素类型是int的deque
    std::list<std::deque<int>> li;
    // 定义并初始化三个deque对象
    std::deque<int> dq1 = {1, 3, 5, 6, 7, 8};
    std::deque<int> dq2 = {10, 30, 91, 100, 30, 40};
    std::deque<int> dq3 = {4, 6, 7, 8, 1, 5, 10, 33};
    // 将三个deque对象保存到list对象的尾部
    li.push_back(dq1);
    li.push_back(dq2);
    li.push_back(dq3);
    // 将所有整数打印的控制台
    for (auto dq : li) {
        for (auto i : dq) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}