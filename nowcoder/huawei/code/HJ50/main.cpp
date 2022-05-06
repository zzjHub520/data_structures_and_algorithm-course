#include <iostream>
#include <stack>

using namespace std;


// 当前运算符与符号栈的栈顶运算符做优先级比较，如果当前优先级高，则不做运算压入栈中，相同进行运算
bool cmp(char c1, char c2) {
    return !((c1 == '(') || ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/')));
}

void doCal(stack<double> &sd, stack<char> &sc) {
    double b = sd.top();
    sd.pop();
    double a = sd.top();
    sd.pop();
    int op = sc.top();
    sc.pop();
    if (op == '+') a = a + b;
    else if (op == '-') a = a - b;
    else if (op == '*') a = a * b;
    else if (op == '/') a = a / b;
    sd.push(a);
}

int main() {
    string mp = "+-*/)]}";
    string str;
    getline(cin, str);

    stack<double> sd;
    stack<char> sc;
    sc.push('(');
    str += ')';
    bool nextIsOp = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            sc.push('(');
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            while (sc.top() != '(') doCal(sd, sc);
            sc.pop();
        } else if (nextIsOp) {
            while (cmp(sc.top(), str[i])) doCal(sd, sc);
            sc.push(str[i]);
            nextIsOp = false;
        } else {
            int j = i;
            if (str[j] == '-' || str[j] == '+') i++;
            while (mp.find(str[i]) == std::string::npos) i++;
            string t = str.substr(j, i - j);
            sd.push((double) stoi(t));
            i--;
            nextIsOp = true;
        }
    }
    cout << sd.top() << endl;

    return 0;
}