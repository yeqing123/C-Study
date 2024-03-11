#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() 
{
    vector<int> ivec;
    int i;
    // 读入一组整数，存入ivec中
    cout << "Enter a few of integers:" << endl;
    while (cin >> i) {
        ivec.push_back(i);
    }
    if (ivec.size() > 0) {
        cout << "Caculate the sum of two adjacent elements:" << endl;
        // 使用迭代器将相邻的一对整数相加
        for (auto it = ivec.cbegin(); it < ivec.cend() - 1; it+=2) {
            cout << *it + *(it + 1) << endl;
        }
        // 当元素数量为奇数时，单独输出最后一个元素
        if (ivec.size() % 2 != 0) {
            cout << *(ivec.cend() - 1) << endl;
        }
        cout << "Caculate the sum of two elements corresponding to first and last:" << endl;
        // 使用迭代器，求首尾相对的两个元素之和
        for (auto it = ivec.cbegin(); it != ivec.cbegin() + ivec.size() / 2; ++it) {
            cout << *it + *(ivec.cend() - (it - ivec.cbegin() + 1)) << endl;
        }
        // 当元素数量为奇数时，单独输出最后一个元素
        if (ivec.size() % 2 != 0) {
            cout << *(ivec.cbegin() + ivec.size() / 2) << endl;
        }
    }
    return 0;
}