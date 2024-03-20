#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 向指定家庭加入新的孩子的名字
void add_chidren(string &surname, multimap<string, string> &families) 
{
    cout << "Enter children's name:(Ctr+Z to end)" << endl;
    string child;
    while (cin >> child) {
        families.insert({surname, child});
    }
}

// 打印一个迭代器对之间的所有元素，该区间表示一个家庭
void print_family(multimap<string, string>::iterator beg, multimap<string, string>::iterator end) 
{
    cout << "Children of the " << beg->first << " family: ";
    while (beg != end) {
        cout << beg->second << " ";
        ++beg;
    }
    cout << endl;
}

// 输出multimap的所有数据
void output_families(multimap<string, string> &families)
{
    cout << "All the children of each family:" << endl;
    if (families.empty()) {   // 判断是否为空
        cout << "No data!" << endl;
        return;
    }
    for (auto fit = families.cbegin(); fit != families.cend();) {
        string surname = fit->first;           // 姓氏
        cout << "Children of the " << surname << " family: ";  // 姓氏只打印一次
        auto beg = families.lower_bound(surname);
        while (beg != families.upper_bound(surname)) {        // 打印以姓氏为关键字的所有元素中的子女名字
            cout << beg->second << " ";
            ++beg;
        }
        cout << endl;
        fit = beg;                           // 指向下一个姓氏
    }
}

int main()
{
     // 因为multimap允许关键字重复，所以也就无需再使用vector保存某一家孩子的名字了
    multimap<string, string> families;  
    cout << "You can get information about existing families, and add new children to it. " 
         << "You can also add a new family to the container." << endl;
    cout << "Okay, try enter a family's surname please, see what children it contains." << endl;
    string surname, cntiu;
    char c;
    while (cin && cntiu != "no" && cntiu != "NO") {
        cout << "Surname: ";
        cin >> surname;
        auto fp = families.equal_range(surname);   // 根据给定的姓氏返回一个pair对象
        if (fp.first != fp.second) {               // 判断是否存在给定姓氏的元素
            print_family(fp.first, fp.second);     // 存在就打印这个家庭的信息
            cout << "Whether add new children?(y or n) ";
        } else {                                  // 不存在
            cout << "This family doesn't exist! Whether add the " << surname << "s family?(y or n) ";   
        }
        cin >> c;
        if (cin && c != 'n' && c != 'N') {
            add_chidren(surname, families);       // 给指定家庭添加新的子女名字
        }
        cout << "Do you continue?(yes or no) ";
        cin.clear();
        cin.sync();
        cin >> cntiu;
    }
    // 打印一个分割线
    cout << "-----------------------" << endl;
    // 输出所有家庭的成员
    output_families(families);
    return 0;
}