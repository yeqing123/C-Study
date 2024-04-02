#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// 在动态内存中创建一个空的int的vector对象
shared_ptr<vector<int>> create()
{
    return make_shared<vector<int>>();  // 创建空的vector对象，并返回指向该对象的shared_ptr指针
}

// 从标准输入中读取数据，保存到vector中
void save(shared_ptr<vector<int>> vp)
{
    int i;
    while (cin >> i) {
        vp->push_back(i);
    }
}

// 打印vector的所有元素
void print(const shared_ptr<vector<int>> vp)
{
    for (auto i : *vp) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    auto vp = create();
    save(vp);
    print(vp);
    // 智能指针会自动释放内存，无需再手动释放
    return 0;
}