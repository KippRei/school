#include <iostream>
#include <iomanip>

void getUserInput(int*);
void getUserExpenses(double*, const int*);
void printTotal(const double*, const int*);

using namespace std;

// Main 
int main() {
    int userInput = 1;
    int* userInputPtr = &userInput;
    getUserInput(userInputPtr);

    double expenseArr[userInput];
    getUserExpenses(expenseArr, userInputPtr);

    return 0;
}

void getUserInput(int* userInputPtr) {
    cout << "How many household expenses are you entering?: ";
    cin >> *userInputPtr;
    cout << endl;
}

void getUserExpenses(double* expenseArr, const int* length) {
    for (int i = 0; i < *length; i++) {
        double expense;
        do {
            cout << "Enter household expense " << i + 1 << ": $";
            cin >> expense;
        } while (expense < 0);

        *(expenseArr + i) = expense;
    }
}

void printTotal(const double* expenseArr, const int* length) {
    
}