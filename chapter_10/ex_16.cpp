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
    // 按字典排序，并消除重复的单词
    elimDups(words);          
    // 使用lambda表达式，按长度排序(短的在前，长的在后)，长度相同的维持字典序
    stable_sort(words.begin(), words.end(), 
        [] (const string &s1, const string &s2)
            { return s1.size() < s2.size(); });
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    auto ws = find_if(words.begin(), words.end(), 
        [sz] (const string &s) { return s.size() >= sz; });
    // 计算满足size() >= sz 的元素数目
    int count = words.end() - ws;
    // 打印符合条件的单词数量
    cout << count << " " << make_plural(count, "word", "s") 
         << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词(每个单词之间用空格分开)
    for_each(ws, words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}