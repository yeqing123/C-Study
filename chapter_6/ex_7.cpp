#include <iostream>
using namespace std;
// 函数在第一次调用时返回0，此后每调用一次返回值加1
size_t record_calls() 
{
    static size_t call_number = 0;
    return call_number++;   // 后置递增，会先返回call_number的副本，然后在执行加1，因此函数第一次被调用时会返回0
}

int main()
{
    for (size_t i = 0; i < 10; ++i) {
        cout << record_calls() << endl;
    }
    return 0;
}