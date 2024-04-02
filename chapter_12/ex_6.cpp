#include <iostream>
#include <vector>

using namespace std;

// 在动态内存中创建一个空的int的vector对象
vector<int>* create_vector()
{
    // 分配动态内存，创建一个vector对象并默认初始化为空
    return new vector<int>;  
}

// 从标准输入中读取数据，保存到vector中
void input_ints(vector<int> *vp)
{
    int i;
    while (cin >> i) {
        vp->push_back(i);
    }
}

// 打印vector的所有元素
void print_ints(const vector<int> *vp)
{
    for (auto i : *vp) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    auto vp = create_vector();
    input_ints(vp);
    print_ints(vp);
    // 谁分配了动态内存，谁就负责释放
    delete vp;
    vp = nullptr;

    return 0;
}