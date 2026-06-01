#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = top;
    top = temp;
    cout << "Pushed: " << val << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;
    cout << "Popped: " << top->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top Element: " << top->data << endl;
}

int main() {
    int choice, val;

    do {
        cout << "\n--- STACK USING LINKED LIST ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

        }

    } while (choice != 0);

    return 0;
}
