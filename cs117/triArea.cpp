// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: TriangleArea.

// Description: Ask for base and height values from user and calculate triangle area

// Program Name submitted to Canvas: Reitzel_Marques_TriangleArea


#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::string;

double getHeight();
double getBase();
double getArea(double, double);
void displayData( double, double, double);
double checkInput(string);

int main() {
    double base = getBase();
    double height = getHeight();
    double area = getArea(height, base);
    displayData(height, base, area);
}


// Get height value from user, validates and returns value
double getHeight() {
    string height = "";
    double dHeight = 0;
    while (dHeight <= 0) {
        cout << "Enter height: ";
        getline(cin, height);
        dHeight = checkInput(height);
        if (dHeight <= 0) {
            cout << "Please enter a positive number.\n";
        }
    }
    return dHeight;
}


// Get base value from user, validates and returns value
double getBase() {
    string base = "";
    double dBase = 0;
    while (dBase <= 0) {
        cout << "Enter base: ";
        getline(cin, base);
        dBase = checkInput(base);
        if (dBase <= 0) {
            cout << "Please enter a positive number.\n";
        }
    }
    return dBase;
}


// Takes height and base and returns area of triangle
double getArea(double h, double b) {
    return (h * b * .5);
}


// Takes data and displays properly
void displayData( double h, double b, double a) {
    int rwidth = 12;
    cout << std::fixed << std::showpoint << std::setprecision(2);
    cout << endl;
    cout << "    Triangle's Area" << endl;
    cout << "-----------------------" << endl;
    cout << setw(10) << std::left << " Base: " << setw(rwidth) << std::right << b << endl;
    cout << setw(10) << std::left << " Height: " << setw(rwidth) << std::right << h << endl;
    cout << setw(10) << std::left << " Area: " << setw(rwidth) << std::right << a << endl;
    cout << endl;
}


// Checks user input to ensure valid input (must be a number)
double checkInput(string userInput) {
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