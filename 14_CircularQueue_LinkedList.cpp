#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
    Node *front, *rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* temp = new Node;
        temp->data = value;

        if (front == NULL) {
            front = rear = temp;
            rear->next = front; // circular link
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front; // maintain circular nature
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

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue (Linked List) ---\n";
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