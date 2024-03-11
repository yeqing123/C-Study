#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    list<int> lst;
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    cout << "Removed all duplicate numbers and copied them to a list container." << endl;
    for (auto s : lst) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}