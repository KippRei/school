// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: Expenses.

// Description: Asks user for number and amount of expenses.
// Description: Sorts expenses, prints expense amounts and total

// Program Name submitted to Canvas: Reitzel_Marques_Expenses


#include <iostream>
#include <iomanip>

void getArrLengthFromUser(int*);
void getUserExpenses(double*, const int*);
void bubbleSort(double*, const int*);
void selectionSort(double*, const int*);
void printTotal(const double*, const int*);

using namespace std;


// Main 
int main() {
    int arrLength = 1;
    int* arrLengthPtr = &arrLength;
    getArrLengthFromUser(arrLengthPtr);

    double expenseArr[arrLength];
    getUserExpenses(expenseArr, arrLengthPtr);
    //bubbleSort(expenseArr, arrLengthPtr);
    selectionSort(expenseArr, arrLengthPtr);
    printTotal(expenseArr, arrLengthPtr);

    return 0;
}


// Get number of expenses from user
void getArrLengthFromUser(int* arrLengthPtr) {
    int userInput = 0;
    do {
        cout << "How many household expenses are you entering?: ";
        cin >> userInput;
        if (userInput <= 0) {
            cout << "The number of items must be greater than 0.\n";
        }
    } while (userInput <= 0);

    *arrLengthPtr = userInput;
    cout << endl;
}


// Get each expense amount from user
void getUserExpenses(double* expenseArr, const int* length) {
    for (int i = 0; i < *length; i++) {
        double expense;
        cout << "Enter household expense " << i + 1 << ": $";
        do {
            cin >> expense;
            if (expense < 0) {
                cout << "Negative amounts are not allowed.\n";
                cout << setw(27) << left << "Enter another amount:" << "$";
            }
        } while (expense < 0);

        *(expenseArr + i) = expense;
    }
}


// Bubble Sort
void bubbleSort(double* expenseArr, const int* length) {
    // Flag to see if any swaps occurred on most recent pass through
    // If no swaps occurred, swapped flag remains false and list must be in order
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 0; i < *length - 1; i++) {
            double* elem1 = (expenseArr + i);
            double* elem2 = (expenseArr + i + 1);
            if (*elem1 > *elem2) {
                double temp = *elem1;
                *elem1 = *elem2;
                *elem2 = temp;
                swapped = true;
            }
        } 
    } while (swapped);
}


// Selection Sort
void selectionSort(double* expensesArr, const int* length) {
    for (int i = 0; i < *length; i++) {
        int lowIndex = i;
        double lowestVal = *(expensesArr + i);
        for (int j = i + 1; j < *length; j++) {
            double currVal = *(expensesArr + j);
            if (currVal < lowestVal) {
                lowestVal = currVal;
                lowIndex = j;
            }
        }
        double temp = *(expensesArr + lowIndex);
        *(expensesArr + lowIndex) = *(expensesArr + i);
        *(expensesArr + i) = temp;
    }
}


// Displays results (sorted expenses and total expenses)
void printTotal(const double* expenseArr, const int* length) {
    double total = 0;

    cout << fixed << showpoint << setprecision(2);
    cout << "\nThe amounts in ascending order, and the totals, are:\n\n";
    cout << "Amount\n";
    cout << "--------\n\n";
    for (int i = 0; i < *length; i++) {
        double amt = *(expenseArr + i);
        cout << "$" << amt << endl;
        total += amt;
    }

    cout << "\nTotal Amount of Expenses : $" << total;
    cout << "\n\n";
}