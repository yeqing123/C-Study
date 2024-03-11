#include <iostream>
#include <vector>
using namespace std;

string make_plural(int count, const string &word)
{
    return count > 1 ? word + "s" : word;
}
// 使用迭代器完成课本93页，划分分数段的程序
int main()
{
    // 定义容器，每10分为一个等级，加上满分100，一个11个分数等级
    vector<int> grade(11, 0);
    unsigned score;
    int cnt = 0;
    // 输入分数
    cout << "Enter a set of scores: " << endl;
    while (cin >> score) {
        // 判断分数是否合法
        if (score <= 100) {
            // 获取指向第一个元素的迭代器
            auto it = grade.begin();
            // 将迭代器移动的正确的位置
            it += score / 10;
            // 将对应位置的元素值加1
            ++*it;
            // 统计有效分数
            cnt++;
        }
    }
    // 输出统计结果
    cout << "You entered a total of " << cnt << " " << make_plural(cnt, "score")
         << ", and the corresponding level is: " << endl;
    for (auto g : grade) {
        cout << g << " ";
    }
    cout << endl;
    return 0;
}