#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::vector;
using std::string;
int main()
{
    // 定义两个字符类型的数组，并初始化
    char ca1[10] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char ca2[11] = {'a', 'b', 'j', 'd', 'e', 'f'};
    char *pbeg1 = begin(ca1), *pend1 = end(ca1);
    char *pbeg2 = begin(ca2), *pend2 = end(ca2);
    // 比较两个数组是否相等
    while (pbeg1 != pend1 && pbeg2 != pend2) {
        if (*pbeg1 != *pbeg2) {
            cout << "Two arrays are not equal!" << endl;
            return 0;
        }
        pbeg1++;
        pbeg2++;
    }
    if (pbeg1 == pend1 && pbeg2 == pend2) {
        cout << "Two arrays are equal!" << endl;
    }

    // 比较两个vector对象是否相等
    vector<char> v1{'a', 'b', 'c', 'j', 'e'}, v2{'a', 'b', 'c', 'd', 'e'};
    if (v1.size() != v2.size()) {
        cout << "Two vectors are not equal!" << endl;
        return 0;
    } else {
        auto it1 = v1.cbegin(), it2 = v2.cbegin();
        while (it1 != v1.cend() && it2 != v2.cend()) {
            if (*it1 != *it2) {
                cout << "Two vectors are not equal!" << endl;
                return 0;
            }
            it1++;
            it2++;
        }
        cout << "Two vectors are equal!" << endl;
    }
    return 0;
}