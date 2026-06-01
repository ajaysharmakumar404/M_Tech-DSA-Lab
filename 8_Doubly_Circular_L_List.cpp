#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* createNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->prev = temp->next = temp;
    return temp;
}

void insertBeg(int val) {
    Node* temp = createNode(val);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* last = head->prev;
    temp->next = head;
    temp->prev = last;
    last->next = temp;
    head->prev = temp;
    head = temp;
}

void insertEnd(int val) {
    Node* temp = createNode(val);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* last = head->prev;
    last->next = temp;
    temp->prev = last;
    temp->next = head;
    head->prev = temp;
}

void insertPos(int pos, int val) {
    if (pos == 1) {
        insertBeg(val);
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
        curr = curr->next;

    if (curr->next == head) {
        cout << "Invalid Position\n";
        return;
    }

    Node* temp = createNode(val);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;
}

void deleteBeg() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;
    Node* temp = head;
    head = head->next;
    last->next = head;
    head->prev = last;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    delete last;
}

void deletePos(int pos) {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos && curr->next != head; i++)
        curr = curr->next;

    if (curr == head) {
        cout << "Invalid Position\n";
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

void display() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    Node* curr = head;
    cout << "List: ";
    do {
        cout << curr->data << " <-> ";
        curr = curr->next;
    } while (curr != head);
    cout << "(HEAD)\n";
}

int countNodes() {
    if (head == NULL) return 0;

    int count = 0;
    Node* curr = head;
    do {
        count++;
        curr = curr->next;
    } while (curr != head);

    return count;
}

int main() {
    int choice, val, pos;

    do {
        cout << "\n--- CIRCULAR DOUBLY LINKED LIST ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Count Nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> val;
                insertBeg(val);
                break;
            case 2:
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Enter position then value: ";
                cin >> pos >> val;
                insertPos(pos, val);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cin >> pos;
                deletePos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Total Nodes: " << countNodes() << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
