#include <iostream>
#include <vector>
using namespace std;
// recursion_output以递归的方式输出vector对象
// vector<int>::const_iterator 类型表示迭代器只能读取，不能写入,
// 该类型可以扩大传入的迭代器的类型范围，如v.cbegin()和v.cend()
void recursive_output(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg == end) {
        cout << endl;
        return ;
    }
    cout << *beg << " ";
    // 注意第一个参数一定要用前置递增运算符，否则会无限递归输出vector对象的一个元素。
    // 或者干脆写成 beg+1 更保险
    recursive_output(++beg, end); 
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    recursive_output(v.cbegin(), v.cend());
    return 0;
}