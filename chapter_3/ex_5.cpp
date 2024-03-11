#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s, result;
    char c;
    // 连续输入多个字符串，并将它们连接成一个大字符串
    cout << "Please enter first string: " << endl;
    while (cin >> s) {
        result += s;
        cout << "Enter the next string again. We will concatenate all the strings together."
             << "(press Ctr+Z to end): " << endl;
    }
    if (result.size()) {
        // 输出大字符串
        cout << "The concatenated string is: \n" << result << endl;
    } else {
        cout << "No string!" << endl;
    }
    cin.clear();
    cin.sync();

    // 再试一次，这次还是连接所有的字符串，但是用一个空格将它们隔开
    result = "";
    cout << "\nTry again. This time we will separate each string with a space." << endl;
    cout << "Please enter first string: " << endl;
    while (cin >> s) {
        if(!result.size()) {   // 第一次输入时，不加空格
            result = s;
        }else {
            result = result + " " + s;
        }
        cout << "Enter the next string again(press Ctr+Z to end): " << endl;
    }
    if (result.size()) {
        // 输出大字符串
        cout << "The concatenated string is: \n" << result << endl;
    } else {
        cout << "No string!" << endl;
    }
    
    return 0;
}