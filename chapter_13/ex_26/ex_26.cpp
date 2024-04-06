#include <iostream>
#include "StrBlob.h"

using namespace std;

void print(const StrBlob &sb)
{
    // 利用StrBlobPtr类，在for循环中遍历打印sb的所有元素
    bool first_word = true;
    auto end = sb.end();
    for (auto p = sb.begin(); neq(p, end); p.incr()) {
        if (first_word) {
            first_word = false;
        } else {
            cout << " ";
        }
        cout << p.deref();
    }
    cout << endl;
}

int main()
{
    StrBlob sb{"I", "am", "learning", "C++"}, sb2(sb), sb3;
    sb3 = sb;
    cout << "Three objects share a single copy of the data:" << endl;
    print(sb);
    print(sb2);
    print(sb3);
    cout << endl;
    
    cout << "Three objects have separate data, and they no longer share one copy:" << endl;
    sb.push_back("and English");
    sb2.push_back("and Java");
    print(sb);
    print(sb2);
    print(sb3);
}