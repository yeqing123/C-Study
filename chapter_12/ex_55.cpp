/*
* 我们已经为chapter_12中的StrBlob类添加了右值引用版本的push_back。
* 此处只需包含该头文件，直接进行测试。
*/
#include <iostream>
#include "../chapter_12/StrBlob.h"    

using namespace std;

int main()
{
    StrBlob sb;
    string s1("c++"), s2("java");
    sb.push_back(s1);         // 调用左值引用版本的push_back
    sb.push_back(s1 + s2);    // 调用右值引用版本的push_back
    sb.push_back("python");   // 调用右值引用版本的push_back

    // 利用头文件中的StrPtr类遍历sb，打印刚刚添加的元素
    for (auto p = sb.begin(); neq(p, sb.end()); p.incr()) {
        cout << p.deref() << endl;
    }
}