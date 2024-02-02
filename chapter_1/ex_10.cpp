# include <iostream>
int main()
{
    int val = 10;
    std::cout << "The integers between 0 and 10 are: " << std::endl;
    while(val > 0){
        std::cout << val << std::endl;
        --val;
    }
    return 0;
}