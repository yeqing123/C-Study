#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int val;
    vector<int> v;
    cout << "Please enter several integers:(press Ctrl+Z to end) " << endl;
    while (cin >> val) {
        v.push_back(val);
    }

    cin.clear();               // 重置标准输入流，否则无法继续读取数值
    cout << "Which number do you want to count?" << endl;
    if (cin >> val) {
        cout << val << " was present " << count(v.cbegin(), v.cend(), val) 
            << " times in the sequence." << endl;
    } else {
        cout << "No data!" << endl;
    }
    return 0;
}