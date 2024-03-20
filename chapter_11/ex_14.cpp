#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Date.h"

using namespace std;

const int space_sz= 20;     // 名字和生日的间隔距离为20个空格

// 去掉字符串两端的空格
void trim(string &s)
{
    if (s.empty()) {
        return ;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

// 解析用户输入的字符串，分离出孩子的名和出生日期
void analyze_string(string &s, string &name, string &birthday)
{
    trim(s);
    auto p = s.find_first_of("\n \t");  // 查找名与出生日期之间的分隔符（假设为换行符、空格或制表符）
    if (p != string::npos) {
        name = s.substr(0, p);
        birthday = s.substr(p);
        trim(birthday);
    } else {                            // 如果没有分隔符，就视为用户只输入了名，没有生日
        name = s;
        birthday.clear();
    }
}

// 从参数二给定的迭代器位置开始，打印参数三指定数量的元素
void output_families(const map<string, vector<pair<string, Date>>> &families, 
    map<string, vector<pair<string, Date>>>::iterator pos, size_t n)
{
    if (families.empty()) {
        cout << "No data!" << endl;
    }
    for (int i = 0; i < n; ++i) {    // 我们假设参数n小于等于map的长度，调用者应该保证n大小合法
        cout << "The " << pos -> first << "'s children and their birthdays:\n";
        if (pos->second.empty()) {   // 判断一个家庭中是否有信息
            cout << "No information about the family!" << endl;
            continue;
        }
        cout << "NAME";
        // 输出space_sz个空格
        for (int i = 0; i < space_sz; ++i) {
            cout << " ";
        }
        cout << "BIRTHDAY" << endl;
        // 打印孩子的名字和生日
        for (auto nd : pos -> second) {
            cout << nd.first;    // 打印名字
            // 让生日与表头中的标题对齐
            for (int i = 0; i < space_sz - nd.first.size() + 4; ++i) {
                cout << " ";
            }
            // 打印生日
            nd.second.print_date(cout) << endl;
        }
        cout << endl;
        ++pos;     // 迭代器后移一位
    }
}

// 向指定家庭中添加子女信息
void add_chidren(vector<pair<string, Date>> &vec) 
{
    string s, child, birthday;
    Date nullDate = Date();         // 定义一个空的Date对象
    cout << "Enter new child's name and birthday(press Ctr+Z to end):" << endl;
    cin.clear();
    cin.sync();
    // 逐行读取由空格分开的名字和生日
    while (getline(cin, s)) {
        analyze_string(s, child, birthday);     // 解析字符串，分离出名字和生日
        if (birthday.empty()) {
            cout << "No birthdy!" << endl;
        } else if (!nullDate.verify(birthday)) { // 判断生日格式是否合法
            cout << "The format is wrong of the date! Please re-enter:" << endl;
            continue;                            // 如果不合法，则将本次输入作废，提示用户重新输入
        }
        // 定义一个lambad表达式，按照名字查找vec中是否存在对应的元素
        auto pos = find_if(vec.cbegin(), vec.cend(), 
                    [child] (const pair<string, Date> &p) { return p.first == child; });
        if (pos != vec.end()) {                  // 如果已经存在，则由用户选择是否替换
            cout << "The child already exists, do to replace?(y or n) ";
            char c;
            cin >> c;
            if (cin && c != 'n' && c != 'N') {
                vec.erase(pos);                  // 删除旧元素
                vec.push_back({child, Date(birthday)}); // 添加新元素，使用列表方式初始化
            }
        } else {                                 // 如果不存在，则直接添加新元素
            vec.push_back(pair<string, Date>(child, Date(birthday)));
        }
        cin.clear();
        cin.sync();
    }
}

void make_families_list(map<string, vector<pair<string, Date>>> &families)
{
    string surname, cnt;
    while (cin && cnt != "no" && cnt != "No") {
        cout << "Surname: ";
        cin >> surname;                          // 输入家庭姓氏                                                                 
        auto fp = families.find(surname);        // 查找map中与姓氏对应家庭成员
        if (fp == families.end()) {              // 如果不存在，则询问是否添加新家庭
            cout << "This family is not exist. Do you add it?(y or n)" << endl;
            char c;
            cin >> c;
            if (cin && c != 'n' && c != 'N') {
                families[surname];               // 添加新家庭
            }
        } else {
            output_families(families, fp, 1);   // 打印找到的家庭成员信息
        }
        // 询问是否要添加新的子女信息
        // 因为map是无序的，所以要重新查找元素位置
        fp = families.find(surname);
        if (fp != families.end()) {  // 如果没有找到说明，用户选择了不添加新家庭
            cout << "Whether to add the children and their birthdays of the family?(y or n)" << endl;
            char c;
            cin.clear();             
            cin.sync();
            cin >> c;
            if (cin && c != 'n' && c != 'N') {
                add_chidren(fp -> second);     // 添加新的子女信息
            } 
        }                                                                                                                                                     
        cout << "Do want continue?(yes or no)" << endl;
        cin.clear();             
        cin.sync();
        cin >> cnt;
    }
}

int main()
{
    // map中的vector保存的是pair类型的元素，它是孩子的名和生日的键值对，
    // 并且我们用第九章练习51创建的Date类来保存生日信息，该类可以识别日期格式是否正确，比用字符串更好。
    map<string, vector<pair<string, Date>>> families; 
    cout << "You can get information about existing families, and add new children and their birthdays to it. " 
         << "You can also add a new family to the container." << endl;
    cout << "Okay, try enter a family's surname please, see what children it contains." << endl; 
    make_families_list(families);
    cout << "-----All the information of the families following:" << endl;
    output_families(families, families.begin(), families.size());
    return 0;
}