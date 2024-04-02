#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 定义类型别名
typedef vector<string>::size_type line_n;  
// 定义全局遍历，方便函数共享数据
vector<string> file;                       
map<string, set<line_n>> wm;

// 净化字符串，去掉所有的标点符号，并全部转换成小写字母
string purify_string(const string &word)
{
    string str;
    for (auto iter = word.begin(); iter != word.end(); ++iter) {
        if (!ispunct(*iter)) {
            str += tolower(*iter);
        }
    }
    return str;
}

// 读取文件，构建查询单词的数据结构
void buildData(ifstream &infile)
{
    string text, word;
    // 逐行读取文本
    while (getline(infile, text)) {
        file.push_back(text);
        istringstream instr(text);
        while (instr >> word) {           // 获取每个单词
            string str = purify_string(word);
            wm[str].insert(file.size());  // 保存单词所在的行号
        }
    }
}

// 查询单词，返回指向行号集合的指针
set<line_n>* query(const string &sought)
{
    static set<line_n> nodata = set<line_n>();  // 定义空集合
    auto iter = wm.find(sought);                // 查询单词
    if (iter != wm.end()) {  
        return &(iter->second);                 // 返回结果集合的地址
    } else {
        return &nodata;                         // 返回空集合的地址
    }
}

// 根据传入的集合指针和单词，打印查询结果
void print_result(const string &s, const set<line_n> *lines)
{
    cout << s << " occurs " << lines->size() 
         << (lines->size() > 1 ? " times" : " time") << endl;
    for (auto li : *lines) {
        int n = li - 1;             // 行号从1开始，file的下标从0开始
        auto iter = file.begin() + n;
        cout << "\t(line " << li << ") " << *iter << endl;
    }
}

// 构建数据结果，与用户交互，查询输入的单词，并打印查询结果
void runQueries(ifstream &infile)
{
    buildData(infile);
    string word;
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        if (!(cin >> word) || word == "q") {
            break;
        }
        auto lines = query(purify_string(word));    // 净化并查询单词，返回指向保存单词行号的集合的指针
        print_result(word, lines);
    }
}

int main()
{
    ifstream infile("input_file.txt");
    if (!infile) {
        cout << "File open failed!" << endl;
        return -1;
    }
    runQueries(infile);
    return 0;
}