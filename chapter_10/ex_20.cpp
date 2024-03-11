#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);
    // 如果只需要统计个数，就不需要调用emilDups和stable_partition了
    // 统计序列中长度超过sz的单词个数          
    int count = count_if(words.begin(), words.end(), [sz](const string &word) -> bool 
        { return word.size() > sz; });
    // 打印符合条件的单词数量
    cout << count << " " << make_plural(count, "word", "s") 
         << " of length more than " << sz << endl;
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 6);
    return 0;
}