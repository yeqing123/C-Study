#include <iostream>
#include "StrBlob.h"

class StrBlobPtrPtr {
public:
    StrBlobPtrPtr(StrBlobPtr sp = StrBlobPtr()) : ptr(&sp) { }
    string *operator->() const
    {
        return ptr->operator->();
    }
private:
    StrBlobPtr *ptr;
};

int main()
{
    StrBlob sb({"hello", "world", "!!!"});
    for (auto p = sb.begin(); p != sb.end(); ++p) {
        StrBlobPtrPtr ptr(p);
        cout << *ptr.operator->() << " ";
    }
    cout << endl;
}