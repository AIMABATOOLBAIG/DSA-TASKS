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
   Function: Insertion Sort
   ========================= */
void insertionSort(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* =========================
   Function: Selection Sort
   ========================= */
void selectionSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find index of minimum element
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap minimum element with first element
        double temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    // Insertion Sort
    insertionSort(salaries1, size);
    cout << "\nAfter Insertion Sort (Ascending Order):\n";
    displayArray(salaries1, size);

    // Selection Sort
    selectionSort(salaries2, size);
    cout << "\nAfter Selection Sort (Ascending Order):\n";
    displayArray(salaries2, size);

    return 0;
}