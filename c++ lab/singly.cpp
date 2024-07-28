#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    delete head;
    head = temp->next;
}

void insertEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }
    
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) return;
    Node* temp = prevNode->next;
    prevNode->next = temp->next;
    delete temp;
}

void traverse(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Testing the functions
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    
    cout << "Circular Linked List: ";
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
