# include <iostream>
int main()
{
    int currVal = 0, cnt = 1;
    // 输入第一个数，确保程序有数字可以处理
    if (std::cin >> currVal) {
        int val = currVal;
        // 在循环中连续输入数字
        while (std::cin >> val){
            if (currVal == val) 
                cnt++;
            else {
                std::cout << currVal << " occurs " 
                          << cnt << " times " << std::endl;
                cnt = 1;
                currVal = val;
            }
        }
    }
    // 打印最后一个数字的个数
    std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    return 0;
}