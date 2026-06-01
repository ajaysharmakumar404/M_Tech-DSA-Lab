#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        // Check overflow
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) { // first element
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;
        cout << value << " inserted\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted\n";

        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue (Array) ---\n";
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