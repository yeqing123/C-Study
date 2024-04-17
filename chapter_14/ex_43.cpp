#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// 定义函数对象，检查给定的值是否可以被数据成员div整除，不能整除返回true，反之返回false
class Aliquant {
public: 
    Aliquant(const modulus<int> &m, int dividend) : mod(m), div(dividend) {}
    bool operator() (int val) {
        return mod(val, div) != 0; 
    }
private:
    modulus<int> mod;
    int div;
};

// 检查向量v中的所有元素是否可以被给定的数整除
bool dividedAll(const vector<int> &v, int dividned)
{
    /*
    * 有两种方式实现该函数
    * 1、使用自定义个的函数对象NotExactDiv
    * 2、使用lambda表达式
    */
    // 方法一：
    Aliquant ali(modulus<int>(), dividned);
    return count_if(v.begin(), v.end(), ali) == 0;
    // 方法二：
    modulus<int> m;
    return count_if(v.begin(), v.end(), [dividned, &m](int val) { return m(val, dividned) != 0; }) == 0;
}

// 使用标准库plus对象，求向量vec中的所有元素之和
int addAll(vector<int> &vec) 
{
    int sum = 0;
    auto addInt = plus<int>();
    for (auto i : vec) {
        sum = addInt(sum, i);
    }
    return sum;
}

int main()
{
    vector<int> vec{2, 4, 6, 8, 10};
    if (dividedAll(vec, 2)) {
        cout << "All elements can be divisible by 2" << endl;
    } else {
        cout << "Not all of the elements are divisible by 2" << endl;
    }

    cout << "add all: " << addAll(vec);
    return 0; 
}