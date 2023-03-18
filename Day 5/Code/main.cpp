#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data = 0, Node *next = nullptr) : data{data}, next{next} {}
};

void ll() {
    Node *head = new Node (12);
    Node *curr = head;
    // cout << head->data << " " << head->next << endl;
    for (int i = 0; i < 10; i++) {
        Node *tmp = new Node(i);
        curr->next = tmp;
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        cout << curr->data << "->";
        curr = curr->next;
    }
}

int main () {
    // Reference operator
    // int x = 10;
    // int &y = x;
    // x = 110;
    // cout << "x : " << x << ", y : " << y << endl;

    // Pointers
    // int x = 10;
    // int *y = &x;
    // cout << "x : " << (*(&x))  << ", y: " << *y << endl;
    
    // Linked List
    ll();
    return 0;
}