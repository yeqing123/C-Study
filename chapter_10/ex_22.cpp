#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;  // 声明bind函数的占位符参数的命名空间

string make_plural(const int count, const string &word, const string &s) 
{
    return count > 1 ? word + s : word;
}

void output_words(vector<string> &words)
{
    for (auto &s : words) {
        cout << s << " ";
    }
    cout << endl;
}

bool check_size(const string &s, vector<string>::size_type sz)
{
    return s.size() <= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);
    // 如果只需要统计个数，就不需要调用elimDups和stable_partition了
    // 使用bind绑定sz，将其传递给check_size函数，统计序列中小于等于sz的单词个数
    int count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    // 打印符合条件的单词数量
    cout << count << " " << make_plural(count, "word", "s") 
         << " of longth less than " << sz << endl;
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 6);
    return 0;
}