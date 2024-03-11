#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    // stable_partition类似于stable_sort，在满足size() >= sz条件的同时，
    // 可以维持原来的排序，即按照字典序排列
    auto true_end = stable_partition(words.begin(), words.end(), 
        [sz] (const string &s) { return s.size() >= sz; });
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