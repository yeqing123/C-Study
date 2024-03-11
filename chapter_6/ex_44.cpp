#include <iostream>
#include <string>
using namespace std;
// 比较两个string对象的长度（将函数定义为内联函数）
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1("hello world"), s2("hello c++");
    cout << "Whether s1 is shorter than s2: "
         << (isShorter(s1, s2) ? "True" : "False") << endl;
    return 0;
}