#include <string>
using namespace std;
//typedef string Type;
//Type iniVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

Exercise::Type Exercise::setVal(Exercise::Type parm) {
    val = parm + initVal();
    return val;
}
