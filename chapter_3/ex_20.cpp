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
    cout << "Please enter some integers:(press Ctr+Z to end)" << endl;
    while (cin >> i) {
        ivec.push_back(i);
    }

    if (ivec.size() > 0) {
        cout << "Caculate the sum of two adjacent elements:" << endl;
        // 输出每对相邻两个整数的和
        for (decltype(ivec.size()) index = 0; index < ivec.size() - 1; index+=2) {
            cout << ivec[index] + ivec[index + 1] << endl;
        }
        // 当元素数量为奇数时，单独输出最后一个元素
        if (ivec.size() % 2 != 0) {
            cout << ivec[ivec.size() - 1] << endl;
        }

        cout << "Caculate the sum of two elements corresponding to first and last:" << endl;
        // 输出第一个和最后一个两个整数的和、第二个和倒数第二个两个整数的和......以此类推
        for (decltype(ivec.size()) index = 0; index < ivec.size() / 2; ++index) {
            cout << ivec[index] + ivec[ivec.size() - 1 - index] << endl;
        }
        // 当元素数量为奇数时，单独输出最后的元素
        if (ivec.size() % 2 != 0) {
            cout << ivec[ivec.size() / 2] << endl;
        }
    } else {
        cout << "No number?!" << endl;
    }
    return 0;
}