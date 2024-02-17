#include <iostream>
using namespace std;
void reset(int &i)
{
    i = 0;
}

int main()
{
    int j = 42;
    // 调用reset将j的值重置为0
    reset(j);
    cout << "j = " << j << endl;
    return 0;
}