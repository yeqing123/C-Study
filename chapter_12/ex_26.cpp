#include <iostream>
#include <memory>

using namespace std;

int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(20);     // 分配20个string类型的裸内存
    string *q = p;                         // 让q指向第一个string的内存
    string s;
    while (cin >> s && q != p + 20) {
        alloc.construct(q++, s);           // 调用construect函数向q指向的位置，构造string对象
    }
    
    // 使用数组
    const size_t size = q - p;
    for (int i = 0; i < size; ++i) {    
        cout << p[i] << " ";
    }
    cout << endl;

    // 销毁已经构造的string对象
    while (q != p) {
        alloc.destroy(--q);
    }
    // 释放全部内存
    alloc.deallocate(p, 20);
    return 0;
}