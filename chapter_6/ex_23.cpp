#include <iostream>
using namespace std;
/*
* 参考书中6.2.4节介绍的内容，定义不同版本的print函数，
* 使每个函数都可以传入int i = 0, j[2] = {0, 1}，两个实参。
*/

void print1(const int *ip) 
{
    if (ip) {
        cout << *ip << endl;
    }
}

void print2(const int *ip, size_t sz)
{
    for (int i = 0; i < sz; ++i) {
        cout << *ip++ << " ";
    }
    cout << endl;
}

void print3(const int *beg, const int *end)
{
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    cout << "print i:" << endl;
    print1(&i);            
    print2(&i, 1);         
    cout << "print j:" << endl;
    print2(j, sizeof(j) / sizeof(*j));        
    print3(begin(j), end(j));    
    return 0;
}