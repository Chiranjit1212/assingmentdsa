#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void insertEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) return;
    Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = prevNode;
    }
    delete temp;
}

void traverse(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Testing the functions
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    
    cout << "Doubly Linked List: ";
    traverse(head);
    
    insertAfter(head->next, 5);
    cout << "After inserting 5 after 2: ";
    traverse(head);

    deleteFirst(head);
    cout << "After deleting first node: ";
    traverse(head);
    
    deleteAfter(head);
    cout << "After deleting node after 1: ";
    traverse(head);

    return 0;
}
