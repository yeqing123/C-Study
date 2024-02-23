#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;
int main()
{
    vector<Person> pvec;
    Person p;
    while (read(cin, p)) {
        pvec.push_back(p);
    }
    for (auto p : pvec) {
        print(cout, p) << endl;
    }
    return 0;
}