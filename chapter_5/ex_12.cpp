#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // 统计包含ff,fl,fi的字符序列的数量，我们设定每个字符只被统计一次
    // 如：xxxxfflxxxx，中ff为1，fl为0，xxxxfffflffixx中ff为2，fl为0，fi为1
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;                  
    char ch, prech = '\0'; 
    cout << "Please enter a piece of text:" << endl;
    while (cin >> ch) {     
        bool jump = false;       // 标记是否跳过已经统计过的字符f
        if (prech == 'f') {  
            switch(ch) {
                case 'f':
                    ++ffCnt;
                    jump = true;  // 一旦f被统计过，就不在参加下一轮的统计
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break; 
            }
        }
        // 字符前移
        if (jump) {
            prech = '\0';  // 已经统计过的f不在重复统计
        } else {
            prech = ch;
        }
        
    }
    cout << "The quantity of ff is: " << ffCnt << endl;
    cout << "The quantity of fl is: " << flCnt << endl;
    cout << "The quantity of fi is: " << fiCnt << endl;
    return 0;
}