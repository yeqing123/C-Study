#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// 使用vector实现同样的猜数字游戏
int main()
{
    const int sz = 5;
    vector<int> iv1, iv2;
    srand((unsigned) time(NULL));  // 创建生成随机数的种子
    // 生成5个0~9的随机数，存入iv1中
    for (int i = 0; i < sz; i++) {
        iv1.push_back(rand() % 10);
    }
    // 该用户猜数字了
    int val, i = 0;
    cout << "Please enter five integers between 0 and 9:" << endl;
    while (cin >> val) {
        if (i < sz) {                  // 将输入5个整数保存到iv2中
            iv2.push_back(val);
            i++;
        }
        if (i == sz) {                 // 当存入5个整数后，判断两个vector是否相等
            // 打印用户输入的号码
            cout << "The numbers of you entered: ";
            for (auto n : iv2) {
                cout << n << " ";
            }
            cout << endl;
            // 比较两个vector是否相等
            auto iter1 = iv1.begin(), iter2 = iv2.begin();
            while (iter1 != iv1.end() && iter2 != iv2.end()) {
                if (*iter1 != *iter2) {     // 当出现不相等时，打印提示信息，并准备下一轮尝试
                    cout << "Unfortunately, you didn't guess right!"
                        << "\nTry again (please press Ctr+Z for exit)" << endl;
                    i = 0;           // 下标重置
                    cin.clear();     // 输入流重置
                    cin.sync();      // 清空输入流的缓存
                    iv2.clear();     // 注意：相比数组的固定长度，vector长度是可变的，因此这里需要将iv2清空，
                    break;
                }
                iter1++;
                iter2++;
            }
            if (iter1 == iv1.end() && iter2 == iv2.end()) {    // 如果所有元素都比较了，说明两个容器相等（用户中奖了）
                cout << "Congratulations, guess right, you won the big prize!!!" << endl;
                return 0;
            }
        }
    }
    // 用户没猜中，但是想退出了，揭晓中奖号码
    cout << "Winning numbers: ";
    for (auto n : iv1) {
        cout << n << " ";
    }
    cout << "\nWelcome again!" << endl;
    return 0;
}