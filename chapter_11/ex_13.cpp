#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string, int>> vec1, vec2, vec3;
    string s;
    int val;
    cout << "Enter a pair of string and integer: " << endl;
    while (cin >> s >> val) {
        // 方法一
        vec1.push_back(pair<string, int>(s, val));  
        // 方法二
        vec2.push_back({s, val});
        // 方法三
        vec3.push_back(make_pair(s, val)); 
    }
    cout << "All pairs in the container following:" << endl;
    cout << "--------vec1:" << endl;
    for (auto p : vec1) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "--------vec2:" << endl;
    for (auto p : vec2) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "--------vec3:" << endl;
    for (auto p : vec3) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}