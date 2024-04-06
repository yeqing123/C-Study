#include <iostream>
#include "HasPtr.h"

using namespace std;

int main()
{
    HasPtr hp("yeqing"), hp2("liusha");
    // hp2 = hp;
    hp2 = std::move(hp);
    print(cout, hp2);
}