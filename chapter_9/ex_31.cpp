#include <iostream>
#include <list>
#include <forward_list>
using namespace std;
int main()
{
    // 使用list容器，修改316页的示例
    list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter++);  // 复制当前元素
            ++iter;                         // list不支持“+=”运算符
            //++iter;
        } else {
            iter = li.erase(iter);          // 删除偶数元素
        }
    }
    // 打印结果
    for (auto e : li) {
        cout << e << " ";
    }
    cout << endl;

    // 使用forward_list容器，修改316页的示例
    forward_list<int> fli{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fli.before_begin(), curr = fli.begin();
    while (curr != fli.end()) {
        if (*curr % 2) {
            curr = fli.insert_after(curr, *curr);  // 在curr之后插入新元素，并返回新元素的迭代器
            prev = curr;                           // prev，curr都前移一步
            ++curr;
        } else {
            curr = fli.erase_after(prev);          // 删除prev后面的偶数，即curr位置上偶数，返回被删除元素之后的元素迭代器
        }
    }
    // 打印结果
    for (auto e : fli) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}