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
    // 按照字典顺序打印作者及其著作题目
    // 因为multimap的数据结构是红黑树，所以其本身就是按照关键字的<运算符进行排序的。
    for (auto elem : authors) {
        cout << elem.first << "\t\"" << elem.second << "\"" << endl;
    }
    return 0;
}