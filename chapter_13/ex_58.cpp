#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo() {}
    Foo(initializer_list<int>);
    Foo(const Foo &f) : data(f.data) { }
    Foo sorted() const &;    // 只能处理左值对象
    Foo sorted() &&;         // 只能处理右值对象
    void print() const;      // 打印data
    
private:
    vector<int> data;
};

// 接受列表形式的构造函数
Foo::Foo(initializer_list<int> li)
{
    for (auto i : li) {
        data.push_back(i);
    }
}

// 左值版本
Foo Foo::sorted() const &
{
    cout << "Lvalue version of sorted" << endl;
    Foo ret(*this);    // 因为左值是const类型，所以必须先获得一个副本
    sort(ret.data.begin(), ret.data.end());  // 对副本进行排序
    return ret;
}

// 右值版本
Foo Foo::sorted() &&
{
    cout << "Rvalue version of sorted" << endl;
    sort(data.begin(), data.end());   // 右值允许修改，故可直接对其排序
    return *this;
}

// 打印元素
void Foo::print() const
{
    for (auto i : data) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Foo f{4, 7, 9, 2, 3, 2, 1, 8, 6, 5};
    std::move(f).sorted().print();  // 调用右值版本的sorted

    f.sorted().print();             // 调用左值版本的sorted
}

