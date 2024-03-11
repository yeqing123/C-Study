#include <iostream>

using namespace std;

int main()
{
    int val = 10;
    // 因为不是只有唯一的return语句，所有需要设置范围类型。
    // 因为要改变val的值，因此采用捕获引用的方式，也可以采用隐式捕获方式，即只保留&
    auto f = [&val] () -> bool   
    {
        if (val == 0) {
            return true;
        } else {
            --val;
            return false;
        }
    };
    while (!f()) {
        cout << val << endl;
    }
    return 0;
}