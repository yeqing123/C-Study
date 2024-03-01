#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
vector<string> to_vector(string&);  // 因为函数定义在后面，所有要在文件开始处先做声明
void caculator(stack<string>&);
int count = 0;
// 函数handing_expresion使用stack适配器处理括号化的表达式
double handle_expression(string &exp) {
    stack<string> stk;
    // 为了简化handle_expression函数，
    // 先调用to_vector函数将字符串表达式，转换成以每个计算单元为元素的vector类型
    vector<string> vexp = to_vector(exp);     
    for (auto s : vexp) {
        if (s == ")") {            // 当遇到右括号时，调用caculator函数从栈中弹出圆括号中的子表达式，并将计算结果push到栈中
            --count;
            caculator(stk);
        } else {
            stk.push(s);          // 将所有除右括号外的元素push的栈中
        }
    }
    caculator(stk);               // 当处理完所有圆括号中的表达式后，计算最终的结果，并push到栈中，此时栈中应该只有一个元素
    if (count != 0) {             // 当处理完整个表达式后count的值应该为0，否则抛出一个异常，提示左右括号不匹配
        throw runtime_error("There is a error in the expression. Parentheses do not match!");
    }
    return stod(stk.top());
}

// 从栈中弹出元素，并计算表达式的结果。计算式按照运算符的优先级，先计算乘除，后算加减
// 经过两轮的处理后，栈中将只保存括号化子表达式的最终结果。
void caculator(stack<string> &stk) {
    stack<string> substk;
    while (!stk.empty()) {
        string s = stk.top();
        stk.pop();
        if (s == "(") {
            ++count;     // 每当出现一个左括号，就记录下来
            break;       // 先只处理括号内的表达之
        }
        // 先计算乘除，将计算结果push到另一个栈中，代替原来的子表达式
        if (s == "*" || s == "/") {
            double val1 = stod(stk.top());
            stk.pop();
            double val2 = stod(substk.top());
            substk.pop();
            if (s == "*") {
                substk.push(to_string(val1 * val2));
            } else if (s == "/") {
                substk.push(to_string(val1 / val2));
            }
        } else {
            substk.push(s);
        }
    }
    // 在上一个while循环中已经计算了表达式的乘除，并将表达式有存入了另一个栈中
    // 下面接着计算加减，并将结果push会原来的栈中
    while (!substk.empty()) {
        string s = substk.top();
        substk.pop();
        if (s == "+" || s == "-") {
            double val1 = stod(stk.top());
            stk.pop();
            double val2 = stod(substk.top());
            substk.pop();
            double result;
            if (s == "+") {
                stk.push(to_string(val1 + val2));
            } else {
                stk.push(to_string(val1 - val2));
            }
        } else {
            stk.push(s);
        }
    }
}

vector<string> to_vector(string &exp) {
    vector<string> v;
    string s = "";
    for (char c : exp) {
        if (isdigit(c) || c == '.') {
            s += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {  // 只保存有效字符，屏蔽掉其他无关字符（如空白字符）
            if (s.size() > 0) {
                v.push_back(s);
                s.clear();
            }
            s += c;
            v.push_back(s);
            s.clear();
        }
    }
    // 保存最后一个数值
    if (s.size() > 0) {
        v.push_back(s);
    }
    return v;
}

int main()
{
    string exp1 = "2.5+2.1*10.1-3";
    string exp2 = "2*((4*4+21*2)/2+3*3+1)/(3+3)";
    cout << exp1 << " = " << handle_expression(exp1) << endl;
    cout << exp2 << " = " << handle_expression(exp2) << endl;
    return 0; 
}