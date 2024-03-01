#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
    list<int> ili{4, 5, 10, 11, 12, 6, 7, 8 ,9, 13, 1, 2, 3, 14, 15};
    deque<int> even_deq, odd_deq;
    for (auto i : ili) {
        // 判断每个元素，如果是偶数就拷贝到even_deq中，如果是奇数就拷贝到odd_deq中
        if (i % 2 == 0) {       // 偶数
            even_deq.push_back(i);
        } else {                // 奇数
            odd_deq.push_back(i);
        }
    }
    // 打印结果
    cout << "even deque: " << endl;
    for (auto e : even_deq) {
        cout << e << " ";
    }
    cout << endl;
    cout << "odd deque: " << endl;
    for (auto o : odd_deq) {
        cout << o << " ";
    }
    cout << endl;

    return 0;
}