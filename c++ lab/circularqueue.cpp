#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int* array;

public:
    CircularQueue(int size) {
        this->size = size;
        array = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] array;
    }

    void enqueue(int data) {
        if ((rear + 1) % size == front) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        array[rear] = data;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << array[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue: ";
    queue.display();

    queue.dequeue();
    cout << "Queue after dequeue: ";
    queue.display();

    return 0;
}
