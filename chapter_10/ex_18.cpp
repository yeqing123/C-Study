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
    // 将words按字典序排序，并删除重复出现的单词
    elimDups(words);
    // 获取一个迭代器，迭代器前面的所有元素都是满足size() >= sz的单词，
    // 从该迭代器开始，后面所有的元素都是size() < sz的单词。
    // 注意：partition无需将所有元素按照长短排序，因此不再需要调用stable_sort函数了
    // 并且partition生成的序列也不再是按字典排序了，即原来的排序无法维持
    auto true_end = partition(words.begin(), words.end(), 
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