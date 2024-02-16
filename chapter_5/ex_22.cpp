#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int sz;
    // 使用do...while 可以代替书中的goto语句
    do {
        sz = get_size();
    } while (sz <= 0);
    return 0;
}