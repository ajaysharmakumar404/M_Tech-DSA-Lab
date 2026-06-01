#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << value << " inserted\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " deleted\n";

        front = front->next;
        if (front == NULL) rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue using Linked List ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}