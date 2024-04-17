#include <iostream>
#include "StrBlob.h"

using namespace std;

void print(const StrBlob &sb) 
{
    auto it = sb.begin();
    while (it != sb.end()) {
        cout << *it << " ";
        cout << it->size() << " ";
        it += 1;
    }
    cout << endl;
}

int main()
{
    const StrBlob sb{"hello", "world", "!!"};
    auto it = sb.begin();
    *it = "okay";
    print(sb);

    return 0;
}