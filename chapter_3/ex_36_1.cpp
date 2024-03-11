#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// 两个数组比较和两个vector比较方法相同，如果两个比较对象的长度不一致，则短的小于长的。
// 如果它们的长度一致，则需要逐一比较每个元素，并且以首次出现不同元素的大小作为两个数组或
// vector的比较结果。
// 为了简化起见，我们假设两个数组和两个vector的长度都是相等的。

// 我们来玩一个猜数字的游戏，看看你输入的5个0~9之间的整数，与程序随机生成的整数是否相等。
int main()
{
    const int sz = 5;
    int ia1[sz], ia2[sz];
    srand((unsigned) time(NULL));  // 创建生成随机数的种子
    // 生成5个0~9的随机数，存入数组ia1中
    for (int i = 0; i < sz; i++) {
        ia1[i] = rand() % 10;
    }
    // 该用户猜数字了
    int val, i = 0;
    cout << "Please enter five integers between 0 and 9:" << endl;
    while (cin >> val) {
        if (i < sz) {                  // 将输入的数值保存到数组中，并保持下标不越界
            ia2[i] = val;
            i++;
        }
        if (i == sz) {                 // 当存满数组后，判断两个数组是否相等
            // 打印用户输入的号码
            cout << "The numbers of you entered: ";
            for (auto n : ia2) {
                cout << n << " ";
            }
            cout << endl;
            // 比较两个数组是否相等
            auto p1 = begin(ia1), p2 = begin(ia2);
            while (p1 != end(ia1) && p2 != end(ia2)) {
                if (*p1 != *p2) {     // 当出现不相等时，打印提示信息，并准备下一轮尝试
                    cout << "Unfortunately, you didn't guess right!"
                        << "\nTry again (please press Ctr+Z for exit)" << endl;
                    i = 0;           // 下标重置
                    cin.clear();     // 输入流重置
                    cin.sync();      // 清空输入流的缓存
                    break;
                }
                p1++;
                p2++;
            }
            if (p1 == end(ia1) && p2 == end(ia2)) {    // 如果所有元素都比较了，说明两个数组相等（用户中奖了）
                cout << "Congratulations, guess right, you won the big prize!!!" << endl;
                return 0;
            }
        }
    }
    // 用户没猜中，但是想退出了，揭晓中奖号码
    cout << "Winning numbers: ";
    for (auto n : ia1) {
        cout << n << " ";
    }
    cout << "\nWelcome again!" << endl;
    return 0;
}