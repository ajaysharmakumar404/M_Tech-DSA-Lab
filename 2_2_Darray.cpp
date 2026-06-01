#include <iostream>
using namespace std;

int main() {
    int a[20][20];
    int r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    int choice;
    cout << "\n1. Insert Row\n2. Delete Row\n3. Insert Column\n4. Delete Column\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        // Insert Row
        int pos;
        cout << "Enter row position to insert (0 to " << r << "): ";
        cin >> pos;

        for (int i = r; i > pos; i--) {
            for (int j = 0; j < c; j++) {
                a[i][j] = a[i - 1][j];
            }
        }

        cout << "Enter elements of new row:\n";
        for (int j = 0; j < c; j++) {
            cin >> a[pos][j];
        }
        r++;
    }

    else if (choice == 2) {
        // Delete Row
        int pos;
        cout << "Enter row position to delete (0 to " << r - 1 << "): ";
        cin >> pos;

        for (int i = pos; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] = a[i + 1][j];
            }
        }
        r--;
    }

    else if (choice == 3) {
        // Insert Column
        int pos;
        cout << "Enter column position to insert (0 to " << c << "): ";
        cin >> pos;

        for (int j = c; j > pos; j--) {
            for (int i = 0; i < r; i++) {
                a[i][j] = a[i][j - 1];
            }
        }

        cout << "Enter elements of new column:\n";
        for (int i = 0; i < r; i++) {
            cin >> a[i][pos];
        }
        c++;
    }

    else if (choice == 4) {
        // Delete Column
        int pos;
        cout << "Enter column position to delete (0 to " << c - 1 << "): ";
        cin >> pos;

        for (int j = pos; j < c - 1; j++) {
            for (int i = 0; i < r; i++) {
                a[i][j] = a[i][j + 1];
            }
        }
        c--;
    }

    cout << "\nUpdated Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
