#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // 为了避免频繁的分配内存空间，造成的额外开销，我们将字符先存入vector容器，再一次性初始化为string
    vector<char> cv; 
    // 注意：不能定义cv时初始化其有100个元素：cv(100)，这表示cv定义时已经有了100个空字符，
    // 后面再存入的字符会添加到尾部，最终cv将有200个元素，其中前100个元素为空字符（浪费空间）。
    // 正确的方法是：定义cv为空，或者调用reserve给cv先设置容量大小为100。
     cv.reserve(100);  // 已知最少要读取100个字符，故先给设定容量为100 
    // 向容器中连续存入26个小写字母，直到存入100个字符为止
    char c = 'a';
    for (int i = 0; i != 100; ++i) {
        if (i % 26 == 0) {  // 每存完26个小写字母，变量c都回归到字母'a'  
            c = 'a';
        } else {
            ++c;           // 因为字符类型可以转换为int类型，并且所有小写字母都是连续存放的，所以可以通过递增运算符改变字母
        }
        cv.push_back(c);   // 存入字母
    }
    // 从cv容器创建一个string对象
    string s(&cv[0], cv.size());
    // 打印结果
    cout << s << endl;
    // 如果cv调用了reserve，则cv.capacity为100，否则cv.capacity为128
    cout << "s.size(): " << s.size() << " cv.capacity(): " << cv.capacity() << endl;
}