# include <iostream>
int main()
{
    std::cout << "Enter two integers: " << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    // 判断v1和v2大小，取较小的值赋给val_1
    int val_1 = (v1 > v2)? v2 : v1;
    // 判断v1和v2的大小，取较大的值赋给val_2
    int val_2 = (v1 < v2)? v2 : v1;

    std::cout << "All the integers between " << v1 << " and " << v2 << " are:" << std::endl;
    while(val_1 <= val_2){
        std::cout << val_1 << std::endl;
        ++val_1;
    } 
    return 0;
}