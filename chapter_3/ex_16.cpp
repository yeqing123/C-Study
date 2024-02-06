#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v1, v2(10), v3(10, 42), v4{10}, v5{10, 2};
    vector<string> v6{10}, v7{10, "hi"};
    // 打印每个vector对象的容量和所有元素的值
    cout << "v1 has " << v1.size() << " elements:" << endl;
    for (auto e : v1) {
        cout << e << endl;
    }
    cout << "v2 has " << v2.size() << " elements:" << endl;
    for (auto e : v2) {
        cout << e << endl;
    }
    cout << "v3 has " << v3.size() << " elements:" << endl;
    for (auto e : v3) {
        cout << e << endl;
    }
    cout << "v4 has " << v4.size() << " elements:" << endl;
    for (auto e : v4) {
        cout << e << endl;
    }
    cout << "v5 has " << v5.size() << " elements:" << endl;
    for (auto e : v5) {
        cout << e << endl;
    }
    cout << "v6 has " << v6.size() << " elements:" << endl;
    for (auto e : v6) {
        cout << e << endl;
    }
    cout << "v7 has " << v7.size() << " elements:" << endl;
    for (auto e : v7) {
        cout << e << endl;
    }
    return 0;
}