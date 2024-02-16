#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 从标准输入中读取两个整数，并计算第一个数除以第二个数的结果
    int i1, i2;
    string repeat;
    do {
        cout << "Please enter two integers: " << endl;
        if (cin >> i1 >> i2) {  // 输入两个整数
            cout << i1 << " / " << i2 << " = "  // 输出第一个整数除以第二个整数的结果
                << i1 / i2 << endl;
        }   
        cout << "Do you continue? Enter 'y' or 'n': " << endl;
        cin >> repeat;
    } while (!repeat.empty() && repeat[0] != 'n');
    
    return 0;
}