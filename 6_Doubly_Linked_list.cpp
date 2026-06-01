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
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void insertBeg(int val) {
    Node* temp = createNode(val);
    if (head != NULL) {
        head->prev = temp;
        temp->next = head;
    }
    head = temp;
}

void insertEnd(int val) {
    Node* temp = createNode(val);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
}

void insertPos(int val, int pos) {
    if (pos == 1) {
        insertBeg(val);
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* temp = createNode(val);
    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = temp;

    curr->next = temp;
}

void deleteBeg() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->prev->next = NULL;
    delete curr;
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
    for (int i = 1; i < pos && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    delete curr;
}

void display() {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    Node* curr = head;
    cout << "List: ";
    while (curr != NULL) {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int countNodes() {
    int count = 0;
    Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    int choice, val, pos;

    do {
        cout << "\n---- DOUBLY LINKED LIST MENU ----\n";
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
                cout << "Enter value: ";
                cin >> val;
                insertBeg(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> pos >> val;
                insertPos(val, pos);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Total Nodes: " << countNodes() << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
