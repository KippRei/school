// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: LargestAndSmallestValue

// Description: Asks user to input 5 numbers and prints the largest and smallest number from user input

// Program Name submitted to Canvas: Reitzel_Marques_LargestAndSmallestValue


#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

void welcomeMsg();
void getValues(double[]);
void displayLrgSml(double[]);


// Main
int main() {
    double values[SIZE];
    welcomeMsg();
    getValues(values);
    displayLrgSml(values);
}


// Display welcome message
void welcomeMsg() {
    cout << "This program will ask you to\n";
    cout << "enter five values, then it will\n";
    cout << "determine the largest and smallest\n";
    cout << "of the values you entered.\n\n";
}


// Get 5 values from user
void getValues(double values[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter a value: ";
        cin >> values[i];
        cout << endl;
    }
}


// Find largest and smallest number and display
void displayLrgSml(double values[]) {
    int i = 0;
    double largest = values[i], smallest = values[i]; // Set largest and smallest to first element of array
    for ( ; i < SIZE; i++) {
        double value = values[i];
        if (value < smallest) smallest = value;
        if (value > largest) largest = value ;
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "The largest value entered is " << largest << endl;
    cout << "The smallest value entered is " << smallest << endl;
}