#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &vec) 
{
    cout << "vec.size(): " << vec.size() << endl;
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << " " << *iter;
    }
    cout << "*" << endl; // 在最后多输出一个星号，标记序列末尾位置
}

// 定义二元谓词isShorter，谓词表示一段可被调用的表达式
bool isShorter(const string &s1, const string &s2) 
{
    return s1.size() < s2.size();
}

void my_elimDups(vector<string> &words) 
{
    sort(words.begin(), words.end());       
    cout << "-----Called sort()-----" << endl;
    output_words(words);
    auto end_unique = unique(words.begin(), words.end()); 
                                                          
    cout << "-----Called unique()-----" << endl;
    output_words(words);                                                                               
    words.erase(end_unique, words.end());                           
    cout << "-----Called erase()-----" << endl;
    output_words(words);
    // 使用谓词isShorter，并调用stabke_sort，将vector中的元素
    // 先按单词长度（由短到长）排序，相同长度的按字典顺序排序
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "-----Called stable_sort()-----" << endl;
    output_words(words);
}

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    my_elimDups(words);    // 调用自定义的my_elimDups函数消除重复单词
    return 0;
}