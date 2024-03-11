#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
int main()
{
    //利用指针将数组元素置为0
    int ia[] = {1, 2, 3, 4, 5, 6, 7};
    // begin函数和end函数分别返回指向数组首元素的指针和指向数组末尾元素的下一个位置的指针
    int *p = begin(ia);       
    while (p != end(ia)) {
        *p = 0;
        p++;
    }
    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}