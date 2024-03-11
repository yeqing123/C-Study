#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 将普通整数转换为序列数，返回字符串
string sequence_value(int val)
{
    string sval = to_string(val);
    switch(val)
    {
        case 1: return sval + "st";
        case 2: return sval + "nd";
        case 3: return sval + "rd";
        default: return sval + "th";
    }
}

int main()
{
    list<int> lst{1, 3, 0, 4, 5, 0, 9, 8, 0, 6};
    auto last_z = find(lst.crbegin(), lst.crend(), 0);
    int cnt = 1;
    ++last_z;         // 让方向迭代器向前移动一位，以便转换为普通迭代器后，依然指向最后一个0
    // 因为list不支持迭代器的算术运算，所以使用一个循环来计算最后一个0的位置
    for (auto iter = lst.cbegin(); iter != last_z.base(); ++iter) {
        ++cnt;
    }
    cout << "The " << sequence_value(cnt) << " element is the last element with a value of 0" << endl;
    return 0;
}