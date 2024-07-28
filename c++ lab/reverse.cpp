#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& stk, int item) {
    if (stk.empty()) {
        stk.push(item);
    } else {
        int top = stk.top();
        stk.pop();
        insertAtBottom(stk, item);
        stk.push(top);
    }
}

void reverseStack(stack<int>& stk) {
    if (!stk.empty()) {
        int item = stk.top();
        stk.pop();
        reverseStack(stk);
        insertAtBottom(stk, item);
    }
}

void printStack(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Original Stack: ";
    printStack(stk);

    reverseStack(stk);
    cout << "Reversed Stack: ";
    printStack(stk);

    return 0;
}
