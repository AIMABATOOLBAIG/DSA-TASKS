#include <iostream>
using namespace std;

/* =========================
   Function: Display Array
   ========================= */
void displayArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* =========================
   QUICK SORT FUNCTIONS
   ========================= */

// Partition function for Quick Sort
int partition(double arr[], int low, int high) {
    double pivot = arr[high];   // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

/* =========================
   MERGE SORT FUNCTIONS
   ========================= */

// Merge two sorted subarrays
void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* =========================
   Main Function
   ========================= */
int main() {
    // Salary data (at least 10 values)
    double salaries1[10] = {
        55000, 42000, 76000, 31000, 68000,
        49000, 83000, 39000, 61000, 45000
    };

    double salaries2[10] = {
        55000, 42000, 76000, 31000, 68000,
        49000, 83000, 39000, 61000, 45000
    };

    int size = 10;

    cout << "Original Salary Data:\n";
    displayArray(salaries1, size);

    // Quick Sort
    quickSort(salaries1, 0, size - 1);
    cout << "\nAfter Quick Sort (Ascending Order):\n";
    displayArray(salaries1, size);

    // Merge Sort
    mergeSort(salaries2, 0, size - 1);
    cout << "\nAfter Merge Sort (Ascending Order):\n";
    displayArray(salaries2, size);

    return 0;
}