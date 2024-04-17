#include <iostream>
#include <functional>
#include <map>

using namespace std;

int main()
{
    map<string, function<int(int, int)>> binOps;
    // 分别添加：加、减、乘、除、取模，五项二元运算对应的键值对
    binOps.insert({"+", plus<int>()});
    binOps.insert({"-", minus<int>()});
    binOps.insert({"*", multiplies<int>()});
    binOps.insert({"/", divides<int>()});
    binOps.insert({"%", modulus<int>()});

    //测试计算器是否正常工作
    int left, right;
    string ops;
    cout << "Enter a binary operation expression for the integer:(press Ctr+Z to end) " << endl;
    while (cin >> left >> ops >> right) {
        cout << binOps[ops](left, right) << endl;
    }

    return 0;
}