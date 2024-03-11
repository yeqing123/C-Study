#include <iostream>
#include <vector>

using namespace std;

// print以递归的方式输出vector对象
void print(const vector<int> &vec, unsigned index)
{
    size_t sz = vec.size();
    if (index == sz) {
        return ;
    }
    cout << vec[index] << endl;
    print(vec, index + 1); 
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(v, 0);
    return 0;
}