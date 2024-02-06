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
    while (cin >> i) {
        ivec.push_back(i);
    }
    if (ivec.size() > 0) {
        // 使用迭代器将相邻的一对整数相加
        for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it) {
            cout << *it + *(it + 1) << endl;
        }

        cout << "-----------------" << endl;
        // 使用迭代器，输出第一个和最后一个两个整数的和、第二个和倒数第二个两个整数的和......以此类推
        auto bit = ivec.cbegin(), eit = ivec.cend();
        while (bit < eit) {
            cout << *bit + *(eit - 1) << endl;
            bit++;
            eit--;
        }
    }
    return 0;
}