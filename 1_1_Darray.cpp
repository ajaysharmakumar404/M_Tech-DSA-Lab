#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice;

    while (true) {
        cout << "\n--- ARRAY OPERATIONS MENU ---\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Search element\n";
        cout << "4. Sort array\n";
        cout << "5. Display array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Insertion
            int pos, value;
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;

            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            n++;
            cout << "Element inserted successfully.\n";
        }

        else if (choice == 2) {
            // Deletion
            int pos;
            cout << "Enter position to delete (0 to " << n - 1 << "): ";
            cin >> pos;

            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            cout << "Element deleted successfully.\n";
        }

        else if (choice == 3) {
            // Searching (Linear Search)
            int key, found = 0;
            cout << "Enter element to search: ";
            cin >> key;

            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at index " << i << endl;
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Element not found.\n";
        }

        else if (choice == 4) {
            // Sorting (Bubble Sort)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            cout << "Array sorted unsuccessfully.\n";
        }

        else if (choice == 5) {
            // Display
            cout << "Array elements: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        else if (choice == 6) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
