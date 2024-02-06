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
        // 输出每对相邻两个整数的和
        for (decltype(ivec.size()) index = 0; index < ivec.size() - 1; ++index) {
            cout << ivec[index] + ivec[index + 1] << endl;
        }

        cout << "-----------------" << endl;
        // 输出第一个和最后一个两个整数的和、第二个和倒数第二个两个整数的和......以此类推
        decltype(ivec.size()) index1 = 0, index2 = ivec.size() - 1;
        while (index1 < index2) {
            cout << ivec[index1] + ivec[index2] << endl;
            index1++;
            index2--;
        }
    }
    return 0;
}