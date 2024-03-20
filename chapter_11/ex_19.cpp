#include <iostream>
#include <set>
#include <fstream>
#include "..\chapter_10\Sales_data.h"

using namespace std;

int main()
{
    typedef bool (*fp) (const Sales_data&, const Sales_data&);  // 定义函数指针fp
    multiset<Sales_data, fp> bookstore(compareIsbn);
    // 验证定义的是否正确
    Sales_data sd;
    ifstream in("..\\chapter_10\\Sales_data.txt");
    if (!in) {
        cout << "Opening file fail!" << endl;
        exit(1);
    }
    string s;
    // 打印文件每行的内容
    while (getline(in, s)) {
        cout << s << endl;
    }

    // 重新创建一个文件输入流，将读取的内容保存到Sales_data对象中
    ifstream in2("..\\chapter_10\\Sales_data.txt");
    while (in2 >> sd) {
        bookstore.insert(sd);
    }
    // 定义并初始化一个multiset的迭代器变量
    multiset<Sales_data, fp>::iterator set_it = bookstore.begin();
    // 输出保存的对象
    while (set_it != bookstore.end()) {
        cout << *set_it << endl;
        ++set_it;
    }
    return 0;
}