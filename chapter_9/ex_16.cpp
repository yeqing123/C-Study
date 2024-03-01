#include <iostream>
#include <vector>
#include <list>
// 修改上一题，比较vector<int>和list<int>中的元素
int main()
{
    std::list<int> li = {1, 2, 3, 4, 5};
    std::vector<int> vec = {1, 2, 4};
    std::vector<int> temp_v;
    // 要使用关系运算符，必须保证两个容器的类型及其元素的类型都相同。
    // 故先调用assgin函数将list容器的内容拷贝给一个临时的vector容器
    temp_v.assign(li.begin(), li.end());
    if (temp_v < vec) {
        std::cout << "li is less than vec." << std::endl;
    } else if (temp_v > vec) {
        std::cout << "li is greater than vec." << std::endl;
    } else {
        std::cout << "li equal vec." << std::endl;
    }
    return 0;
}