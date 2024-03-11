#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(vector<string> &vec) {
    cout << "vec.size(): " << vec.size() << endl;
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << " " << *iter;
    }
    cout << "*" << endl; // 在最后多输出一个星号，标记序列末尾位置
}

// 编写自己的elimDups函数，并输入单词序列“the quick red fox jumps over the slow red turtle”
// 进行测试
void my_elimDups(vector<string> &words) {
    sort(words.begin(), words.end());       // 给单词序列按照字典顺序排序
    cout << "-----Called sort()-----" << endl;
    output(words);
    auto end_unique = unique(words.begin(), words.end()); // 将指定范围内重复的单词放在范围序列的末尾，
                                                          // 返回位于不重复元素之后的迭代器 
    cout << "-----Called unique()-----" << endl;
    output(words);                                        // 注意：调佣unique之后重复单词并没有真的被删除，只是移到了序列的末尾，
                                                          // 序列长度依然是10，并且在本人的系统内，最后一个元素red单词变成空字符串
    words.erase(end_unique, words.end());                 // 使用容器成员函数，删除重复单词
    cout << "-----Called erase()-----" << endl;
    output(words);
}

int main()
{
    vector<string> words;
    string s;
    cout << "Please enter a sequence of repeated words are present: " << endl;
    while (cin >> s) {
        words.push_back(s);
    }
    my_elimDups(words);    // 调用函数并输入单词序列“the quick red fox jumps over the slow red turtle”
    return 0;
}