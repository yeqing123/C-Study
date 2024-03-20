#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    map<int, string> m;
    map<int, string>::iterator map_it = m.begin();
    // map的迭代器是value_key类型的值引用，对其解引用得到的是一个pair类型的对象，
    // 其中的first成员保存的是const关键字，不能对其进行修改，只能修改second成员保存的值
    map_it->second = "hello";
    cout << map_it->first << " " << map_it->second << endl;

    return 0;
}