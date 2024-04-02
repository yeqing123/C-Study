#include <iostream>
#include <fstream>
#include "StrBlob.h"

using namespace std;

int main()
{
    ifstream fin("input_file.txt");
    if(!fin) {
        cout << "File open failed!" << endl;
        return -1;
    }
    StrBlob sb;
    string s;
    while (getline(fin, s)) {
        sb.push_back(s);
    }
    for (auto ptr = sb.begin(); neq(ptr, sb.end()); ptr.incr()) {
        cout << ptr.deref() << endl;
    }
    return 0;
}