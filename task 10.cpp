#include <iostream>
using namespace std;

/* =========================
   Function to perform
   Bubble Sort
   ========================= */
void bubbleSort(double salaries[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Flag to detect swapping
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                // Swap salaries
                double temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swapping occurred, array is already sorted
        if (!swapped)
            break;
    }
}

/* =========================
   Function to display
   salary array
   ========================= */
void displaySalaries(double salaries[], int size) {
    for (int i = 0; i < size; i++) {
        cout << salaries[i] << " ";
    }
    cout << endl;
}

/* =========================
   Main Function
   ========================= */
int main() {
    // Array of employee salaries (at least 10 values)
    double salaries[10] = {
        55000, 42000, 76000, 31000, 68000,
        49000, 83000, 39000, 61000, 45000
    };

    int size = 10;

    cout << "Employee Salaries (Before Sorting):\n";
    displaySalaries(salaries, size);

    // Sorting salaries using Bubble Sort
    bubbleSort(salaries, size);

    cout << "\nEmployee Salaries (After Sorting - Ascending Order):\n";
    displaySalaries(salaries, size);

    return 0;
}