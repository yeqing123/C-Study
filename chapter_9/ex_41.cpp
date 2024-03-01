#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // 从vector<char>初始化一个string
    vector<char> cv{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    // 因为我们只能从string或char*类型初始化一个string，所以必须只能向构造函数传入cv第一个元素的地址，
    // 并且从char*创建string时，如果指针所指的数组不是以空字符结尾，则必须指定要拷贝的字符数量，
    // 因此，我们传入cv的长度，表示要拷贝的字符数量。
    string s(&cv[0], cv.size()); 
    cout << s << endl;
    return 0;
}