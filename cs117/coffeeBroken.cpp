// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: CoffeePricewitAddIns.

// Description: Look up and print price of coffee order including add-ins.

// Program Name submitted to Canvas: Reitzel_Marques_CoffeewithAddIns


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 6;
const double BASE_COFFEE_PRICE = 4;

void welcomeMsg();
void populateArrays(string[], double[]);
void displayAddIns(string[]);
void getAddIns(string[], double[]);


// Main
int main() {
    string addInNames[SIZE];
    double addInCosts[SIZE];
    welcomeMsg();
    populateArrays(addInNames, addInCosts);
    getAddIns(addInNames, addInCosts);
}


// Welcome message
void welcomeMsg() {
    cout << "Welcome to the coffee shop!\n";
    cout << "The base price for coffee is $4.00\n";
    cout << "Here are the available add-ins:\n\n";
}


// Populate add-in arrays with names and costs of add-ins
void populateArrays(string addInNames[], double addInCosts[]) {
    addInNames[0] = "Cream";
    addInCosts[0] = 0.50;
    addInNames[1] = "Cinnamon";
    addInCosts[1] = 0.75;
    addInNames[2] = "Chocolate";
    addInCosts[2] = 0.75;
    addInNames[3] = "Amaretto";
    addInCosts[3] = 2;
    addInNames[4] = "Whiskey";
    addInCosts[4] = 2.5;
    addInNames[5] = "None";
    addInCosts[5] = 0;
}


// Displays add-in list
void displayAddIns(string addInNames[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << addInNames[i] << endl;
    }
    cout << "\n"; // For spacing
}

// Ask user for add-ins
void getAddIns(string addInNames[], double addInCosts[]) {
    static double totalCost = BASE_COFFEE_PRICE; // Static variable to hold total cost of coffee w/ add-ins
    cout << fixed << showpoint << setprecision(2);
    displayAddIns(addInNames); // Display add-in names
    while (true) {
        string addIn = "";
        cout << "Enter your choice or enter \"stop or quit:\n";
        cin >> addIn;
        
        for (auto &c : addIn) c = toupper(c); // Convert user input to all uppercase
        
        if (addIn == "STOP") break; // Ends loop (and program) if user inputs "stop"
        
        for (int i = 0; i < SIZE; i++) {
            string toCheck = addInNames[i];
            for (char &c : toCheck) c = toupper(c); // Converts add-in name to uppercase to check against formatted user input
            if (addIn == toCheck) {
                totalCost += addInCosts[i];
                cout << "Add-in Price is $" << addInCosts[i] << endl;
                cout << "Your price including your add-in is " << totalCost << endl;
                cout << endl;
            }
        }
    }
}