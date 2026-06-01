#include <iostream>
using namespace std;

// Utility function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// a) Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// b) Optimized Bubble Sort
void optimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break; // already sorted
    }
}

// c) Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// d) Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Partition for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// e) Quick Sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Merge for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

// f) Merge Sort
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// Main function
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], temp[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i]; // copy for reuse
    }

    // Bubble Sort
    bubbleSort(temp, n);
    cout << "\nBubble Sort: ";
    printArray(temp, n);

    // Optimized Bubble Sort
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    optimizedBubbleSort(temp, n);
    cout << "Optimized Bubble Sort: ";
    printArray(temp, n);

    // Insertion Sort
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    insertionSort(temp, n);
    cout << "Insertion Sort: ";
    printArray(temp, n);

    // Selection Sort
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    selectionSort(temp, n);
    cout << "Selection Sort: ";
    printArray(temp, n);

    // Quick Sort
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    quickSort(temp, 0, n-1);
    cout << "Quick Sort: ";
    printArray(temp, n);

    // Merge Sort
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    mergeSort(temp, 0, n-1);
    cout << "Merge Sort: ";
    printArray(temp, n);

    return 0;
}