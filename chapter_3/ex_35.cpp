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
    int *pbeg = begin(ia);
    int *pend = end(ia);
    while (pbeg != pend) {
        *pbeg = 0;
        pbeg++;
    }
    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}