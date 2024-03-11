#include <iostream>
using namespace std;
// 函数在第一次调用时返回0，此后每调用一次返回值加1
unsigned call_count() 
{
    static unsigned calCnt = -1;
    ++calCnt;
    return calCnt; 
}

int main()
{
    for (size_t i = 0; i < 10; ++i) {
        cout << "The number of executions call_count is " << call_count() << endl;
    }
    return 0;
}