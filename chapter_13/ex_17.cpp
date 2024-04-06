#include <iostream>

using namespace std;

unsigned cnt = 0;

struct Numbered {
    Numbered() : mysn(cnt++) { }
    Numbered(const Numbered &) : mysn(cnt++) { }  // 拷贝构造函数，没拷贝一个新的对象都会生成一个新的序号
    unsigned mysn;
};

void f(const Numbered &s) { cout << s.mysn << endl; }

int main()
{
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
/*
* 假设对象序号从0开始：
* 一、当没有定义拷贝构造函数时，无论进行多少次拷贝对象的需要都不会增加，因此输出的结果为：0，0，0
* 二、当定义了拷贝构造函数时，输出结果为：3，4，5。因为在调用函数f之前
* 已经执行了两次拷贝（b=a, c=b），对象的序号增加到了2，此后每调用一次函数都会进行一次实参拷贝，
* 所以f(a)输出3，f(b)输出4，f(c)输出5。
* 三、当使用引用类型作为函数参数时，调用函数不会发生拷贝。
* 因此a、b、c三个对象的序号，都是它们各自创建时的序号。f(a)输出0，f(b)输出1，f(c)输出2。
*/