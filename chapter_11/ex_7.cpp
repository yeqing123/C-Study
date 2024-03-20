#include <iostream>
#include <vector>
#include <map>

using namespace std;

void add_chidren(string &surname, map<string, vector<string>> &families) 
{
    string child;
    cin.clear();
    cin.sync();
    cout << "Enter children's name(press Ctr+Z to end): " << endl;
    while (cin >> child) {
        families[surname].push_back(child);
    }
}

bool get_family(string &surname, map<string, vector<string>> &families)
{
    auto iter = families.find(surname);   // 使用关键词在map中查找对应的元素，如果找到了返回指向该元素位置的迭代器，否则返回指向尾后位置迭代器
    if (iter != families.end()) {         // 如果找到了，就直接打印该元素信息，并返回true
        cout << "The children of the " << surname << " family:" << endl;
        for (auto s : iter -> second) {
            cout << s << " ";
        }
        cout << endl;
        return true;
    } else {                             // 如果找不到，询问是否添加新家庭
        char c;
        cout << "This family is not exist. Do you add it?(y or n)" << endl;
        cin.clear();
        cin.sync();
        cin >> c;
        if (!cin) {
            exit(1);
        } else if (c != 'n') {
            families[surname];          // 创建一个键为姓氏、值为空容器的新元素
            return true;
        }
    }
    return false;                      // 如果没有找到，并且用户也不想创建新元素时，返回false
}

void make_families_list(map<string, vector<string>> &families)
{
    cout << "You can get information about existing families, and add new children to it. " 
         << "You can also add a new family to the container." << endl;
    cout << "Okay, try enter a family's surname please, see what children it contains." << endl;
    string surname, cnt;
    while (cin && cnt != "no") {
        cout << "Surname: ";
        cin >> surname;             // 输入家庭姓氏                                                                 
        if (!cin) {                 // 如果输入流结束，则程序异常退出
            exit(1);
        } else if (get_family(surname, families)) {  // 查找map中与姓氏对应家庭成员
            cout << "Whether to add the children of the family?(y or n)" << endl;
            char c;
            cin.clear();           // 因为要多次使用cin对象，所以使用前先重置并清理缓存
            cin.sync();
            cin >> c;
            if (!cin) {
                exit(1);
            } else if (c != 'n') {   // 如果找到了或者创建了新元素，则继续向容器中添加子女姓名
                add_chidren(surname, families);
            } 
        }                                                                                                                                                              
        cout << "Do want continue?(yes or no)" << endl;
        cin.clear();             // 每次使用cin先，先重置并清空缓存，防止上一次输入残留的数据被再次读取
        cin.sync();
        cin >> cnt;
    }
}

void output_families(const map<string, vector<string>> &families)
{
    if (families.empty()) {
        return;
    }
    cout << "-----All the information of the families following:" << endl;
    for (auto f : families) {
        cout << "The " << f.first << "'s children:\n\t";
        for (auto c : f.second) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main()
{
    map<string, vector<string>> families;
    make_families_list(families);
    output_families(families);
    return 0;
}