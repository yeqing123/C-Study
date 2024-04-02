#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    StrBlob b1;
    {
        StrBlob b2({"aab", "bbc", "ccd"});
        b1 = b2;                   // b2的智能指针的引用计数为2，b1的指针计数为0，b1中原来的data成员对象将自动销毁。
        b2.push_back("eef");       // b2和b2将共享同一个vector对象
    }
    cout << "b1 size: " << b1.size() << endl;
    cout << b1.front() << endl;

    cout << "All elements of the b1:" << endl;
    while (!b1.empty()) {
        cout << b1.back() << " ";
        b1.pop_back();
    }
    cout << endl;
    cout << "b1 size: " << b1.size() << endl;
   
    return 0;
}