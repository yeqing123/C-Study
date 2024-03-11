#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> ivec = {2, 4, 6, 8, 10};
    int iarr[ivec.size()];
    // 要将ivec中的元素拷贝给数组，只能遍历ivec的所有元素，逐一拷贝
    for (unsigned index = 0; index < ivec.size(); index++) {
        iarr[index] = ivec[index];
    }
    // 打印拷贝结果
    for (auto e : ivec) {
        cout << e << endl;
    }
    return 0;
}