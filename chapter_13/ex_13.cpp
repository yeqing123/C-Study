#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct X {
    X() { cout << "constructor X()" << endl; }
    X(const X&) { cout << "copy constructor X(const X&)" << endl; }
    ~X() { cout << "destructor ~X()" << endl; }
    X &operator=(const X&) { cout << "copy-assignment operator" << endl; }  
};

void fun1(const X x) 
{
   
}

void fun2(const X &x) 
{
   
}

int main()
{
    cout << "Dynamic memory allocation:" << endl;
    X *p = new X;
    cout << endl;

    cout << "Local vairable:" << endl;
    X x;
    cout << endl;

    cout << "Pass on non-reference argument:" << endl;
    fun1(x);
    cout << endl;

    cout << "Pass on reference argument:" << endl;
    fun2(x);
    cout << endl;

    cout << "Add to the container:" << endl;
    vector<X> vec;
    vec.push_back(x);
    cout << endl;

    cout << "Release the dynamically alloced memory:" << endl;
    delete p;
    cout << endl;

    cout << "Indirect initialization and assignment:" << endl;
    X y = x;
    y = x;
    cout << endl;

    cout << "End of program" << endl;
}