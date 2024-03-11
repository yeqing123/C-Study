#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> ivec;
    // 定义一个随机数种子
    srand((unsigned) time(NULL));
    // 随机生成10个100以内的整数
    for (int i = 0; i < 10; ++i) {
        ivec.push_back(rand() % 100);
    }
    // 打印所有整数
    for (auto iter = ivec.cbegin(); iter != ivec.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    // 将所有的奇数翻倍
    cout << "Double all of the odd numbers:" << endl;
    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
        // 条件表达式，因为%的优先级高于!=，!=的优先级高于条件运算符，
        // 所以不用加括号也可以得出正确的结果，但是为了提高表达式的可读性还是加上括号更好
        *iter = (*iter % 2 != 0) ? *iter * 2 : *iter;   
    }
    // 再次打印结果
    for (auto iter = ivec.cbegin(); iter != ivec.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

}