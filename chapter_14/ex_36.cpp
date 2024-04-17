#include <iostream>
#include <vector>
#include "ReadString.h"

using namespace std;

int main()
{
    ReadString rs;
    vector<string> vec;
    
    while (true) {
        string line = rs();
        if (!line.empty()) {
            vec.push_back(line);
        } else {   // 如果是空行，结束while循环
            break;
        }
    }

    for (auto s : vec) {
        cout << s << endl;
    }

    return 0;
}