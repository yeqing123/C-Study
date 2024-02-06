#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    // 使用包含整型元素的vector对象，初始化一个整型数组
    vector<int> ivec = {2, 4, 6, 8, 10};
    int iarr[ivec.size()];
    for (unsigned index = 0; index < ivec.size(); index++) {
        iarr[index] = ivec[index];
    }
    // 打印拷贝结果
    for (auto e : ivec) {
        cout << e << endl;
    }
    return 0;
}