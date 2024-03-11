#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for (auto iter = beg; iter != end; ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

// 函数size_last_five确定字符串是否至少包含5个字符，返回一个布尔值
bool size_least_five(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    output_words(words.begin(), words.end());
    // 标准库函数protition对words进行重组，将size_least_five返回值为true的元素放在序列的前半部分，
    // 将返回值为false的元素放在后半部分，返回一个迭代器，指向最后一个为true的元素之后的位置。
    auto true_end = partition(words.begin(), words.end(), size_least_five);
    // 打印长度大于等于5的单词
    output_words(words.begin(), true_end);
    return 0;
}