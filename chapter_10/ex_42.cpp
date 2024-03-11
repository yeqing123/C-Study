#include <iostream>
#include <list>

using namespace std;

void output_words(const list<string> &words)
{
    for (auto word : words) {
        cout << word << " ";
    }
    cout << endl;
}

void elim_Dups(list<string> &words) 
{
    // 使用list的成员函数sort为单词排序
    words.sort();
    output_words(words);
    // 使用unique成员函数消除重复单词
    words.unique();
    output_words(words);
}

int main()
{
    list<string> words;
    string s;
    cout << "Enter some words:(press Ctr+Z to end)" << endl;
    while (cin >> s) {
        words.push_back(s);
    }
    elim_Dups(words);
    
    return 0;
}