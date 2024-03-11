#include <iostream>
using namespace std;
void reset(int &i)
{
    i = 0;
}

int main()
{
    int j = 42;
    cout << "Before resetting: j = " << j << endl;
    // 调用reset将j的值重置为0
    reset(j);
    cout << "After resetting: j = " << j << endl;
    return 0;
}