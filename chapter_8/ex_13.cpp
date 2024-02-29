#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
// 重写书中288页的示例，让程序从一个命名文件中读取数据，而不是从cin对象
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    vector<PersonInfo> people;
    string line, s;
    ifstream fin("person_info.txt");        // 创建ifstream对象，并打开文件
    // 从文件的输入流中逐行读取信息，直至遇到结束符或出现其他错误
    while (getline(fin, line)) {
        istringstream record(line);       
        PersonInfo info;
        record >> info.name;               // 从字符串流中读取姓名，并保存在PersonInfo对象中
        while (record >> s) {              // 然后读取电话号码并保存，直到字符串结束
            info.phones.push_back(s);
        }
        people.push_back(info);
    }
    // 处理完所有数据后，将people中保存的信息打印出来
    for (auto info : people) {
        cout << info.name << " ";
        for (auto s : info.phones) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}