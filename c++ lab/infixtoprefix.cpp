#include <iostream>
#include <stack>
#include <algorithm>
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

string infixToPrefix(string infix) {
    stack<char> operators;
    stack<string> operands;

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string op1 = operands.top();
                operands.pop();

                string op2 = operands.top();
                operands.pop();

                string temp = op + op2 + op1;
                operands.push(temp);
            }
            operators.pop();
        } else if (!isOperator(infix[i])) {
            operands.push(string(1, infix[i]));
        } else {
            while (!operators.empty() && precedence(infix[i]) <= precedence(operators.top())) {
                char op = operators.top();
                operators.pop();

                string op1 = operands.top();
                operands.pop();

                string op2 = operands.top();
                operands.pop();

                string temp = op + op2 + op1;
                operands.push(temp);
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        string op1 = operands.top();
        operands.pop();

        string op2 = operands.top();
        operands.pop();

        string temp = op + op2 + op1;
        operands.push(temp);
    }

    return operands.top();
}

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << "Infix: " << infix << endl;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string prefix = infixToPrefix(infix);
    reverse(prefix.begin(), prefix.end());
    cout << "Prefix: " << prefix << endl;

    return 0;
}
