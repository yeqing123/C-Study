#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> authors;
    authors.insert({"Linus Torvalds", "Just for fun"});
    authors.insert({"Lewis Carroll", "Alice's Adventure in Wonderland"});
    authors.insert({"Daniel Defoe", "The life and strange surprising adventures of Robinson Crusoe"});
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    string name;
    cout << "Enter the name of an author: ";
    getline(cin, name);
    auto pos = authors.find(name);     // 使用find查找指定作者对应的元素
    if (pos == authors.end()) {
        cout << "The author does not exist!." << endl;  // 作者不存在
        return -1;
    }
    // 如果存在，就删除该作者的所有著作名
    while (pos != authors.end()) {
        authors.erase(pos);
        pos = authors.find(name);  // 重新查找
    }
    cout << name << " has been deleted." << endl;
    // 打印删除后的所有元素
    cout << "---------------------------" << endl;
    for (auto elem : authors) {
        cout << elem.first << "\t\"" << elem.second << "\"" << endl;
    }
    return 0;
}