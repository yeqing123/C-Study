// #define NDEBUG
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    string s;
    string sought = "aaa";
    while (cin >> s && s != sought) {
        cout << "Didn't find!" << endl;
    }
    // 当用户终止输入时，assert输出错误提示并终止程序
    assert(cin);   // 当关闭调试器后，该语句就不在有效。
                   // 因为用户结束输入应该属于正常操作，所以不应该以此作为assert的判断条件。
    cout << "You found it!" << endl;
    return 0;
}