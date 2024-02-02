# include <iostream>
int main()
{
    int v1, v2;
    std::cout << "Enter two integers:" << std::endl;
    std::cin >> v1 >> v2;
    // 取v1和v2两个整数中较小的一个赋给变量val_1
    int val_1 = (v1 < v2)? v1:v2;
    // 取v1和v2两个整数中较大的一个赋给变量val_2
    int val_2 = (v1 < v2)? v2:v1;

    std::cout << "All the integers between " << val_1 << " and " << val_2 << " are:" << std::endl;
    for(int i = val_1; i <= val_2; i++)
        std::cout << i << std::endl;

    return 0;

}