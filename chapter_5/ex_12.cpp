#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 统计包含ff,fl,fi的字符序列的数量
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;                  
    string str;    // 保存字符序列
    cout << "Please enter a piece of text:" << endl;
    
    while (cin >> str) {  
        // find()查找字符序列中包含子序列，如果包含则返回子序列所在位置的下标，否则返回string::npos
        if (str.find("ff") != string::npos) {
            ++ffCnt;
        } 
        if (str.find("fl") != string::npos) {
            ++flCnt;
        } 
        if (str.find("fi") != string::npos) {
            ++fiCnt;
        }
    }
    cout << "Number of character sequences containing ff: " << ffCnt << endl;
    cout << "Number of character sequences containing fl: " << flCnt << endl;
    cout << "Number of character sequences containing fi: " << fiCnt << endl;
    return 0;
}