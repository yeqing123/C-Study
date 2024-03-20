#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string, int>> vec;
    string s;
    int val;
    cout << "Enter a pair of string and integer: " << endl;
    while (cin >> s >> val) {
        vec.push_back(pair<string, int>(s, val));
    }
    cout << "All pairs in the container following:" << endl;
    for (auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}