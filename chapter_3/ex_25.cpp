#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
// 使用迭代器完成课本93页，划分分数段的程序
int main()
{
    // 定义容器，每10分为一个等级，加上满分100，一个11个分数等级
    vector<int> grade(11, 0);
    unsigned score;
    // 输入分数
    while (cin >> score) {
        // 判断分数是否合法
        if (score <= 100) {
            // 获取指向第一个元素的迭代器
            auto it = grade.begin();
            // 将迭代器移动的正确的位置
            it += score / 10;
            // 将对应位置的元素值加1
            *it += 1;
        }
    }
    // 输出统计结果
    for (auto g : grade) {
        cout << g << " ";
    }
    cout << endl;
    return 0;
}