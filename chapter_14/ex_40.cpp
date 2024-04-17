#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查给定的第一个字符串长度是否小于第二个字符串
class IsShorter {
public:
    bool operator() (const string &a, const string &b) 
    {
        return a.size() < b.size();
    }
};

// 检查给定的字符串长度是否大于等于某个值
class StrNotShorterThan {
public:
    StrNotShorterThan(size_t n) : len(n) { }
    bool operator() (const string &s) 
    {
        return s.size() >= len;
    }
private:
    size_t len;
};

// 打印给定的字符串到给定的输出流（默认为标准输出流），并用给定的字符隔开（默认为空格）
class PrintString {
public: 
    PrintString(ostream & o = cout, char c = ' ') : sep(c), os(o) { }
    void operator() (const string &s) 
    {
        os << s << sep;
    }
private:
    ostream &os;
    char sep;
};

void elimDups(vector<string> &words)
{
    // 按字典序排序，以便查找重复单词
    sort(words.begin(), words.end());
    // unique重排输入范围，使得每个单词只出现一次
    auto end_unique = unique(words.begin(), words.end());
    // 使用向量操作删除重复单词
    words.erase(end_unique, words.end());
}

string make_plural(int count, string word, string suffix)
{
    return count > 1 ? word + suffix : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);     // 将words按字典顺序排序，删除重复单词
    // 创建IsShorter对象
    IsShorter isShorter;
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), isShorter);
    // 创建StrNotShorterThan对象
    StrNotShorterThan sNotShorter(sz);
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    auto wc = find_if(words.begin(), words.end(), sNotShorter);
    // 计算满足size() >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") 
         << " of length " << sz << " or longer" << endl;
    // 创建PrintString对象
    PrintString printer;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(), printer);
    cout << endl;
}

int main()
{
    vector<string> words{"The", "quick", "red", "rabbit", "jump", "over", "the", "slow", "red", "tortoise"};
    biggies(words, 4);
    return 0;
}