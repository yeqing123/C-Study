#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class StrLenIs {
public:
    StrLenIs(size_t n) : len(n) { }
    bool operator() (const string &s) {
        return s.size() == len;
    }
private:
    size_t len;
};

// 去掉单词两端的空白字符和标点符号
string pure_words(const string &word)
{
    const char *b = word.c_str();    // 将字符串转换成字符数组，b指向数组首元素
    const char *e = b + word.size(); // e指向数组末尾的空字符
    // b指向字符串中的第一个字母
    while (b < e) {
        if (isalpha(*b)) {
            break;
        }
        ++b;
    }
    // e指向字符串中的最后一个字母
    while (b < e) {
        if (isalpha(*e)) {
            break;
        }
        --e;
    }
    string s;
    // 移除字符串两端的非字母字符，保留中间的剩余部分
    if (*e != '\0' || b < e) {  // 如果b和e均指向空字符，则什么也不做
        while (b <= e) {
            s.insert(s.size(), 1, *b);
            ++b;
        }
    }
    return s;
}

// 从文件输入流中读取并保存单词
void save_words(ifstream &fin, vector<string> &words) 
{
    string s;
    while (fin >> s) {
        string pw = pure_words(s);
        if (!pw.empty()) {     // 不保存空字符串
            words.push_back(pw);
        }
    }
}

int main()
{
    ifstream fin("input_file.txt");
    if (!fin) {
        cout << "Open file failed!" << endl;
        return -1;
    }
    vector<string> words;
    save_words(fin, words);  // 保存文件的单词

    // 利用SizeCheck对象，统计长度从1到10的单词的数量
    for (auto i = 1; i <= 10; ++i) {
        StrLenIs lenIs(i);
        cout << "size: " << i << ", cnt: "
             << count_if(words.begin(), words.end(), lenIs) << endl; // 使用算法count_if才能使程序更简化
    }
    return 0;
}