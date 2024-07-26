// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: LargestAndSmallestValue

// Description: Asks user to input 5 numbers and prints the largest and smallest number from user input

// Program Name submitted to Canvas: Reitzel_Marques_LargestAndSmallestValue


#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>

using std::cout;
using std::cin;
using std::string;

void promptUser(double[]);
void displayHighLow(double[]);
double stringToDouble(string);

const int SIZE = 5; // Length of array


// Main
int main() {
    double valArr[SIZE]; // Array to hold list of numbers
    promptUser(valArr);
    displayHighLow(valArr);
}


// Prompt user for values, check/convert input to double and insert into array
void promptUser(double valArr[]) {
    cout << "This program will ask you to enter the five values, then it will determine the largest and smallest of the values you entered.\n";

    // Get user input, convert to double, and add to valArr array
    for (int i = 0; i < SIZE; i++) {
        double value = 0;
        string userInput = "";
        while (!value) {
            cout << "\nEnter a value: ";
            getline(cin, userInput);
            value = stringToDouble(userInput);
            if (value) {
                valArr[i] = value;
            }
            else {
                cout << "Invalid input. Please enter a number.\n";
            }
        }
    }
}


// Finds the highest and lowest numbers and displays
void displayHighLow(double valArr[]) {
    double highest = -std::numeric_limits<double>::max();
    double lowest = std::numeric_limits<double>::max();
    
    for (int i = 0; i < SIZE; i++) {
        if (valArr[i] > highest) {
            highest = valArr[i];
        }
        if (valArr[i] < lowest) {
            lowest = valArr[i];
        }
    }

    cout << std::fixed << std::showpoint << std::setprecision(2);
    cout << "\nThe largest value entered is " << highest;
    cout << "\nThe smallest value entered is " << lowest << std::endl;
}


// Attempts to convert string to double, returns 0 on error
double stringToDouble(string userInput) {
    double validatedNum = 0;
  
    try {
        size_t pos;
        validatedNum = std::stod(userInput, &pos);
        if (pos < userInput.size()) {
            throw(userInput);
        }
        else {
            return validatedNum;
        }
    }
    catch (...) {
        return 0;
    }
}