#include <iostream>
#include <sstream>
#include <vector>
// 修改书中的示例，使istringstream对象record定义在循环的外面
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    vector<PersonInfo> people;
    string line, s;
    istringstream record;                  // 将istringstream对象定义在循环的外面
    // 从标准输入流中逐行读取信息，直至遇到结束符或出现其他错误
    while (getline(cin, line)) {
        record.str(line);                  // 将读取的数据拷贝到istringstream对象中
        PersonInfo info;
        record >> info.name;               // 读取姓名，并保存在PersonInfo对象中
        while (record >> s) {              // 然后读取电话号码并保存，直到字符串结束
            info.phones.push_back(s);
        }
        record.clear();                    // 必须重置istringstream对象，否则无法继续使用
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