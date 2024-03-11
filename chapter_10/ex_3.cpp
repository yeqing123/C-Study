#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{12, 3, 4, 6, 8, 9, 10};
    int sum = accumulate(v.cbegin(), v.cend(), 0); 
    cout << "The sum of all the elements is " << sum << endl;
    return 0;
}