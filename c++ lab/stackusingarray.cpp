#include <iostream>
using namespace std;

class Stack {
    int top;
    int capacity;
    int* array;

public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void push(int data) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        array[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack: ";
    stack.display();

    stack.pop();
    cout << "Stack after pop: ";
    stack.display();

    return 0;
}
