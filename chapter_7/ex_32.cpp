#include <iostream>
#include <vector>
#include "Window_mgr.h"
using namespace std;
int main() 
{
    Window_mgr wm;
    vector<Screen> &screens = wm.get_screens();
    cout << "Before calling clear():" << endl;
    screens[0].display(cout);  // 输出默认的唯一元素的内容

    wm.clear(0);   // 将元素对象中的contents设置为空白字符
    cout << "After calling clear():" << endl;
    screens[0].display(cout);  // 输出清理结果

    cout << screens[0].size() << endl;

    return 0;
}

