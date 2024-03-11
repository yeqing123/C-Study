#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

void output_vec(vector<int> &vec) 
{
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

bool check_size(int val, string::size_type sz)
{
    int int_sz = sz;   // 需要先将s.size()返回的无符号类型转换成int类型
    return val > int_sz;
}

void biggies(vector<int> vc, const string &s)
{
    cout << "s.size(): " << s.size() << endl;
    // 使用bing函数绑定字符串，传递给check_size函数。自己是接受一个参数（vec的元素）
    // find_if会返回一个迭代器，指向vec中第一个大于字符串长度的元素
    auto iter = find_if(vc.begin(), vc.end(), bind(check_size, _1, s.size()));
    // 判断并打印结果
    if (iter != vc.end()) {
        cout << "The first element that is greater than the string length is " << *iter << endl;
    } else {
        cout << "No such element is persent in the container!" << endl;
    }
}

int main()
{
    vector<int> vec{-3, -1, 3, 5, 7, 9, 10, 14, 15, 20, 22};
    output_vec(vec);
    biggies(vec, "hello world!");
    biggies(vec, "hello!");
    biggies(vec, "hi!");
    biggies(vec, "");
    return 0;
}