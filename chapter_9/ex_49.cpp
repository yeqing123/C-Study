#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>   // 导入标准库中的algorithm头文件
using namespace std;
// 从一个文件流中读取单词，找出既不包含上出头部分（ascender），也不包含下出头部分（descender）的单词，保存到一个string的vector中
vector<string> find_words(ifstream& ifs) {
    vector<string> v1, v2;                               // 定义两个容器，v1保存了所有符合条件的单词，v2保存了所有符合条件的最长的单词
    string ascenders("bdfhijklt"), descenders("gjpqy");  // 定义两个字符串，分别包含了所有上出头部分字母和下出头部分字母
    string word;
    int length = 0;                                      // 用于保存符合条件的最长单词的长度
    while (ifs >> word) {                                // 从文件流中读取每个单词
        if (word.find_first_of(ascenders) == string::npos && 
                word.find_first_of(descenders) == string::npos) {  // 判断读取的单词是不是既不包含上出头字母，也不包含下出头字母
            v1.push_back(word);                               // 将所有符合条件的单词，保存在v1中
            if (word.size() > length) {                       
                length = word.size();                       
            }
        }
    }
    // 遍历v1，并找出最长的单词存入v2中，注意：已经存入的单词不再重复保存
    for (auto w : v1) {
        // 判断元素是否为最长单词，并且该单词再v2中还未保存
        // algorithm中的find函数，用于判断单词w是否已经存在于v2中
        if (w.size() == length && find(v2.begin(), v2.end(), w) == v2.end()) {
            v2.push_back(w);       // 将v2中还没有的最长单词，存入v2中
        }
    }
    return v2;  
}

int main()
{
    ifstream ifs("words_file.txt");      // 创建文件输入流，并打开一个命名文件
    vector<string> v = find_words(ifs);
    cout << "The longest word of match condition in the file is: " << endl;
    for (auto w : v) {
        cout << w << endl;
    }
    return 0;
}