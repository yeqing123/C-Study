#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("words.txt");      
    istream_iterator<string> in_iter(in), eof; 
    vector<string> vec;
    while (in_iter != eof) {
        vec.push_back(*in_iter++);    // 通过输入流迭代器从文件中读取字符串
    }
    cout << "Output all contents of the file: " << endl;
    ostream_iterator<string> out_iter(cout, " ");   // 创建输出流迭代器，每操作一次该迭代器就在后面打印一个空格字符串
    // for (auto s : vec) {
    //     *out_iter++ = s;     
    // }
    
    // 也可以使用copy来打印vector中的元素，更简洁
    copy(vec.cbegin(), vec.cend(), out_iter);
    cout << endl;

    return 0;
}