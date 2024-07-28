#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < infix.size(); i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "(A+B)*(C-D)";
    cout << "Infix: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}
