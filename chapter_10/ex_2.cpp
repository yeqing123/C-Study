#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    string s;
    list<string> v;
    cout << "Please enter several strings:(press Ctrl+Z to end) " << endl;
    while (cin >> s) {
        v.push_back(s);
    }

    cin.clear();               // 重置标准输入流，否则无法继续读取数值
    cout << "Which string do you want to count?" << endl;
    if (cin >> s) {
        cout << s << " was present " << count(v.cbegin(), v.cend(), s) 
            << " times in the container." << endl;
    } else {
        cout << "No data!" << endl;
    }
    return 0;
}