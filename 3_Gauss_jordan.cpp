#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    float a[20][21];

    cout << "Enter number of variables: ";
    cin >> n;

    cout << "Enter augmented matrix (row-wise) for Gauss jordan method:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Gauss-Jordan Elimination
    for (int i = 0; i < n; i++) {
        // Make diagonal element = 1
        float pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        // Make other elements in column = 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2)
             << a[i][n] << endl;
    }

    return 0;
}
