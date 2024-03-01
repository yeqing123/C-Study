#include <iostream>
#include <vector>
using namespace std;
// print函数将vector对象的元素打印到指定的输出流
ostream& print(ostream &os, vector<int> vec) {
    for (auto elem : vec) {
        os << elem << " ";
    }
    return os;
}

int main()
{
    // 用6种不同的方法定义并初始化vector对象
    vector<int> vec1;
    vector<int> vec2(5);
    vector<int> vec3(5, -1);
    vector<int> vec4{2, 4, 5, 7, 8, 6};
    vector<int> vec5(vec3);
    vector<int> vec6(vec4.begin() + 1, vec4.end()); // 初始化vec4的一个子序

    // 打印每个对象，看看它们都包含哪些值
    print(cout, vec1) << endl;
    print(cout, vec2) << endl;
    print(cout, vec3) << endl;
    print(cout, vec4) << endl;
    print(cout, vec5) << endl;
    print(cout, vec6) << endl;

    return 0;
}
