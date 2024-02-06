#include <iostream>
#include <string>
using std::string;
string sa[10];
int ia[10];
int main() 
{
    string sa2[10];
    int ia2[10];

    std::cout << "outside sa" << std::endl;
    for (auto e : sa) {
        std::cout << e << std::endl;
    }
    std::cout << "outside ia" << std::endl;
    for (auto e : ia) {
        std::cout << e << std::endl;
    }
    std::cout << "inside sa2" << std::endl;
    for (auto e : sa2) {
        std::cout << e << std::endl;
    }
    std::cout << "inside ia2" << std::endl;
    for (auto e : ia2) {
        std::cout << e << std::endl;
    }
    return 0;
}