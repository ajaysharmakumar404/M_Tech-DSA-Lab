#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    float a[20][21], x[20];

    cout << "Enter number of variables: ";
    cin >> n;

    cout << "Enter augmented matrix (row-wise)for Gauss Elimination method:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            float factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(2) << x[i] << endl;
    }

    return 0;
}
