// 先声明X和Y两个类类型
class X;
class Y;

// Y虽然还没有定义，但是允许定义指向Y类型的指针
class X {
    Y *py;
};

class Y {
    X *px;
};