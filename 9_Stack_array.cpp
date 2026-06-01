#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = val;
    cout << "Pushed: " << val << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stackArr[top--] << endl;
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Top Element: " << stackArr[top] << endl;
}

int main() {
    int choice, val;

    do {
        cout << "\n--- STACK USING ARRAY ---\n";
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
