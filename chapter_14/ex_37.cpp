#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntCompare {
public:
    IntCompare(int i) : val(i) { }
    bool operator()(int i) const 
    {
        return val == i;
    }
private:
    int val;
};

int main()
{
    vector<int> iv{4, 3, 6, 3, 8, 3, 3};
    int newVal = 0, oldVal = 3;
    IntCompare icmp(oldVal);    // 创建IntCompare对象时，向构造函数传入oldVal实参
    
    // 因为IntCompare类重载了函数调用运算符，因此我们可以像使用函数一样使用该类的对象。
    replace_if(iv.begin(), iv.end(), icmp, newVal); 

    for (auto i : iv) {
        cout << i << " ";
    }
    cout << endl;
}