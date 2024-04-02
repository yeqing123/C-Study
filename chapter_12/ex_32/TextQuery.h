#ifndef MY_TEXTQUERY_H
#define MY_TEXTQUERY_H
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include "../StrBlob.h"

using namespace std;

// 在头文件开始位置，先做必要的声明
class QueryResult;
string purify_string(const string&);

class TextQuery {
friend class QueryResult;
public:
    typedef vector<string>::size_type line_n;  // 定义保存行号的类型别名
    TextQuery(ifstream &);
    QueryResult query(const string&) const;
private:
    StrBlob file;
    map<string, shared_ptr<set<line_n>>> wm;  // 保存“单词--所在行号”键值对的map
};

TextQuery::TextQuery(ifstream &infile) : file(StrBlob())
{
    string text, word;
    // 逐行读取文件内容
    while (getline(infile, text)) {
        file.push_back(text);                        // 将每行文本保存到vector中
        istringstream instr(text);
        // 获取每个单词
        while (instr >> word) {
            auto &lines = wm[purify_string(word)];   // 保存净化后的单词，返回值的引用类型
            if (!lines) {                            // 如果lines为空指针，则分配新的内存
                lines.reset(new set<line_n>);
            }
            lines->insert(file.size());              // 保存行号，正好就是file的元素数量
        }
    }
}


// 创建QueryResult类
class QueryResult {
friend ostream &print(ostream&, const QueryResult&);
public:
    typedef vector<string>::size_type line_n;
    QueryResult() {}                            // 为了测试程序，定义一个默认构造函数
    QueryResult(const string &w, StrBlob f,
                shared_ptr<set<line_n>> l) : 
        word(w), file(f), lines(l) { }
private:
    string word;
    StrBlob file;                              // 指向包含文件内容的vector指针
    shared_ptr<set<line_n>> lines;             // 指向包含行号的set指针
};

// query函数要写在QueryResult定义之后
QueryResult TextQuery::query(const string &sought) const
{
    const static shared_ptr<set<line_n>> noline(new set<line_n>);// 创建一个指向空set的指针
    auto iter = wm.find(purify_string(sought));                  // 在map中查找是否存在单词对应的元素
    if (iter != wm.end()) {
        return QueryResult(sought, file, iter->second);          // 如果存在，创建并返回包含结果的QueryResult对象
    } else {
        return QueryResult(sought, file, noline);                // 如果不存在，创建一个空的QueryResult对象
    }
}

ostream &print(ostream &os, const QueryResult &qr)
{
    auto lines = qr.lines;                  // 获取指向包含行号的指针，如果单词不存在，lines->size()正好为0
    cout << qr.word << " occurs " << lines->size() 
         << (lines->size() > 1 ? " times" : " time") << endl;
         
    for (auto li : *lines) {
        auto ptr =  qr.file.begin();        // 返回一个StrBlobPtr对象，它指向file的首元素
        ptr.incr(li - 1);                   // 将ptr的当前位置前移li - 1位（行号减1即是下标）
        cout << "\t(line " << li << ") " << ptr.deref() << endl;
    }
    return os;
}

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
#endif

