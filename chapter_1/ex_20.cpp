#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book;
    cout << "Please enter the sales record of the book:(Ctrl+Z end)" << endl;
    while (cin >> book) {
        cout << "ISBN, quantity sold, sales and average price: " << book << endl;
    }
    return 0;
}