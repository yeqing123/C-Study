# include <iostream>
int main()
{
    int sum = 0, value = 0;
    // 输入任意数量的数字（按Ctrl+Z结束），并为它们求和
    while (std::cin >> value)
        sum += value;

    std::cout << "Sum is " << sum << std::endl;

    return 0;
}