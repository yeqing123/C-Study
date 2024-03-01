#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // 定义两个vector容器，分别保存整型字符串和浮点数字符串
    vector<string> iv{"12", "30", "6", "101", "203", "47", "86"},
                   fv{"10.5", "11.86", "30.89", "1.56", "3.14"};
    int isum = 0;                     // 保存整型值的和
    cout << "integer elements: ";
    for (auto s : iv) {
        cout << s << " ";
        int i = stoi(s);              // 将每个元素转换成整型数值
        isum += i;                    // 累计求和
    }
    cout << endl;
    cout << "sum: " << isum << endl;  // 打印结果

    double fsum = 0;                  // 保存浮点型值的和
    cout << "float elements: ";
    for (auto s : fv) {
        cout << s << " ";
        double f = stof(s);           // 将每个元素转换成浮点型数值    
        fsum += f;                    // 累计求和
    }
    cout << endl;
    cout << "sum: " << fsum << endl;  // 打印结果
    return 0;
}