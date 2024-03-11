#include <iostream>
using namespace std;

int add(int a) 
{
    auto sum = [a] (const int b) { return a + b; };
    return sum(1);
}

int main()
{
    cout << add(3) << endl;
    cout << add(4) << endl;
    return 0;
}