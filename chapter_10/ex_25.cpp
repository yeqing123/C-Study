#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

string make_plural(const int count, const string &word, const string &s) 
{
    return count > 1 ? word + s : word;
}

void elimDups(vector<string> &words)
{
    // 将words按字典序排序
    sort(words.begin(), words.end());
    // 将重复出现的单词放在序列末尾
    auto unique_end = unique(words.begin(), words.end());
    // 删除重复出现的单词
    words.erase(unique_end, words.end());
}

bool check_size(const string &s, vector<string>::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // 将words按字典序排序，并删除重复出现的单词
    elimDups(words);
    // 使用bind和check_size函数，代替原来的lembda
    auto true_end = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    // 计算满足size() >= sz 的元素数目
    int count = true_end - words.begin();
    // 打印长度大于等于给定值的单词，及其数量
    cout << count << " " << make_plural(count, "word", "s") 
         << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), true_end, [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}