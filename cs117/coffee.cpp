// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: CoffeePricewitAdd-Ins.

// Description: Look up and print price of coffee order including add-ins.

// Program Name submitted to Canvas: Reitzel_Marques_CoffeewithAddIns


#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

// A data structure to hold name and price of add-in
struct addIn {
    string name;
    float cost;
};

void welcomeMsg();
void populateAddInsArr(addIn[]);
void displayAddins(addIn[]);
string getUserChoice();
void takeOrder(addIn[]);
void editOrder(vector<addIn>&, float&);
void finalizeOrder(const vector<addIn>&, const float);
int stringToInt(string);
void fakeClearScreen();

// Number of elements in add-in array
const int ARR_SIZE = 6;
// Price of coffee
const float BASE_COFFEE_PRICE = 4;


// Main
int main() {
    addIn addInsArr[ARR_SIZE];
    populateAddInsArr(addInsArr);
    welcomeMsg();
    takeOrder(addInsArr);
}


// Create addIn object with name and price for each item and add to array
void populateAddInsArr(addIn addInsArr[]) {
    addIn cream, cinnamon, chocolate, amaretto, whiskey, none;
    cream.name = "Cream";
    cream.cost = 0.50;
    cinnamon.name = "Cinnamon";
    cinnamon.cost = 0.75;
    chocolate.name = "Chocolate";
    chocolate.cost = 0.75;
    amaretto.name = "Amaretto";
    amaretto.cost = 2;
    whiskey.name = "Whiskey";
    whiskey.cost = 2.5;
    none.name = "None"; // TODO: is this meant to clear add-ins?
    none.cost = 0;

    addInsArr[0] = cream;
    addInsArr[1] = cinnamon;
    addInsArr[2] = chocolate;
    addInsArr[3] = amaretto;
    addInsArr[4] = whiskey;
    addInsArr[5] = none;
}


// Display welcome message
void welcomeMsg() {
    fakeClearScreen();
    cout << "Welcome to The Coffee Shop!\n";
    cout << "The base price for coffee is $4.00\n";
    cout << "Here are the available add-ins:\n\n";
}


// Display list of add-ins
void displayAddins(addIn addInsArr[]) {
    cout << "Add-Ins:\n";
    cout << string(23, '-') << std::endl;
    cout << std::fixed << std::showpoint << std::setprecision(2);
    for (int i = 0; i < ARR_SIZE; i++) {
        addIn item = addInsArr[i];
        string name = "(" + std::to_string(i+1) + ") " + item.name + ":";
        cout << std::setw(17) << std::left << name << "+$" << item.cost << std::endl;
    }
}


// Asks user for add-ins and gets order total
void takeOrder(addIn addInsArr[]) {
    float totalPrice = BASE_COFFEE_PRICE;
    string userChoice = ""; // Holds user menu choice
    vector<addIn> addInList; // Dynamic array for holding add-ins chosen by user

    while (true) {
        displayAddins(addInsArr);
        bool validItem = false; // Flag used to display error message if user input is invalid (sets to true on valid user input)
        userChoice = getUserChoice();

        if (userChoice == "DONE" || userChoice == "-1") {
            finalizeOrder(addInList, totalPrice);
            break;
        }
        else if (userChoice == "ORDER" || userChoice == "0") {
            editOrder(addInList, totalPrice);
            continue;
        }

        // Loop through array of add-ins and check against user input
        for (int i = 0; i < ARR_SIZE; i++) {
            string addInName = addInsArr[i].name;
            for (auto &c: addInName) c = toupper(c); // convert add-in name to uppercase

            if (userChoice ==  addInName || userChoice == std::to_string(i+1)) {
                validItem = true;  // Valid choice, set flag to true
                totalPrice += addInsArr[i].cost; // Add add-in price to total
                addInList.push_back(addInsArr[i]); // Add add-in to vector containing current customer add-ins
                fakeClearScreen();
                cout << "Add-in price is: $" << addInsArr[i].cost << std::endl;
                cout << "Your price including your add-ins is $" << totalPrice << "\n\n";
            }
        }

        if (!validItem) {
            fakeClearScreen();
            cout << "Invalid option, please try again.\n\n";
        }
    }
}


// Get user menu choice
string getUserChoice() {
    string userChoice = "";
    cout << "\nEnter your choice (name or number)\n";
    cout << "(Enter \"order\" or \"0\" to see current order)\n";
    cout << "(Enter \"done\" or \"-1\" when done)\n";
    cout << "Selection: ";
    getline(cin, userChoice);
    for (auto &c: userChoice) c = toupper(c); // convert user input to all uppercase
    return userChoice;
}


// Allows for editing of order (removal of add-ins)
void editOrder(vector<addIn> &addInList, float &totalPrice) {
    fakeClearScreen();

    while (true) {
        string userInput = ""; // Holds user menu choice

        // Display current order (with add-ins)
        cout << "Current order:\n";
        cout << std::setw(17) << std::left << "Coffee" << "$" << BASE_COFFEE_PRICE << std::endl;
        for (int i = 0; i < addInList.size(); i++) {
            addIn item = addInList[i];
            string name = "(" + std::to_string(i+1) + ") +" + item.name;
            cout << std::setw(17) << std::left << name << "$" << item.cost << std::endl;
        }

        // Display total price of order and ask for user input
        cout << string(23, '-') << std::endl;
        cout << std::setw(17) << std::left << "Total" << "$" << totalPrice << std::endl;
        cout << std::endl;
        cout << "Enter number to remove add-in or type \"exit\" or \"0\" to return to add-in screen: ";
        getline(cin, userInput);

        // Convert user input to all uppercase to see if 'exit' was typed
        for (auto &c: userInput) c = toupper(c);

        // Convert user input to int (and subtract 1 for proper index) for removing add-ins from order (addInList)
        int iToRemove = stringToInt(userInput) - 1;

        // Process user input
        if (iToRemove >= 0 && addInList.size() >= iToRemove + 1) {
            totalPrice -= addInList[iToRemove].cost;
            addInList.erase(addInList.begin() + iToRemove);
            fakeClearScreen();
        }
        else if (userInput == "CLEAR") {
            while (addInList.size() > 0) {
                totalPrice -= addInList[0].cost;
                addInList.erase(addInList.begin());
            }
            fakeClearScreen();
        }
        else if (iToRemove == -1 || userInput == "EXIT") {
            break;
        }
        else {
            fakeClearScreen();
            cout << "\nInvalid option, please try again.\n\n";
        }
    }
    fakeClearScreen();
}


// Finalized order
void finalizeOrder(const vector<addIn> &addInList, const float totalPrice) {
    fakeClearScreen();
    int numOfAddIns = addInList.size();

    // Display final order
    if (numOfAddIns > 0) {
        cout << "You ordered a coffee with ";
        for (int i = 0; i < numOfAddIns; i++) {
            string addInLwrCase = addInList[i].name;
            for (auto &c: addInLwrCase) c = tolower(c);

            if (i == numOfAddIns - 1 && numOfAddIns > 1) {
                cout << " and " << addInLwrCase << ".\n";
            }
            else if (i == numOfAddIns -2) {
                cout << addInLwrCase;
            }
            else {
                cout << addInLwrCase << ", ";
            }
        }
    }
    else {
        cout << "You ordered a coffee with no add-ins.\n";
    }

    // Display final total and thank you message
    cout << "Your total is $" << totalPrice << ".\n";
    cout << "Thank you for choosing The Coffee Shop!\n\n";
}


// "Clear" screen by spamming endl
void fakeClearScreen() {
    int lines = 50;
    for (int i = 0; i < lines; i++) {
        cout << std::endl;
    }
}


// Attempts to convert string to int, returns -1 on error
int stringToInt(string userInput) {
    double validatedNum = 0;
  
    try {
        size_t pos;
        validatedNum = std::stoi(userInput, &pos);
        if (pos < userInput.size()) {
            throw(userInput);
        }
        else {
            return validatedNum;
        }
    }
    catch (...) {
        return -1;
    }
}