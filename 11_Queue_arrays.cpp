#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;

        arr[++rear] = value;
        cout << value << " inserted\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front++] << " deleted\n";
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue using Array ---\n";
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