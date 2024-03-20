#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    // 使用vector保存不重复的单词
    vector<string> unique_words;
    ifstream in("words.txt");
    if (!in) {
        cout << "Opening file fail!";
        exit(1);
    }
    string word;
    while (in >> word) {
        cout << word << " ";    // 打印文件中的所有单词
        // 查找是否已经存在重复单词，如果没有再存入容器
        if (find(unique_words.cbegin(), unique_words.cend(), word) == unique_words.end()) {
            unique_words.push_back(word);
        }
    }
    cout << endl;
    cout << "\n-----The container contains only words that are not repeated:" << endl;
    for (auto word : unique_words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}