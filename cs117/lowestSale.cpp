#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <vector> 
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::ifstream;
using std::vector;

double getSalesAmt(string);
void findLowest(const map<string, double>&);
vector<string> getSalesNamesFromFile(const char*);
vector<string> getSalesNamesDefault();
double checkInput(string);

int main(int argc, char *argv[]) {
    vector<string> salesNames; // create vector (dynamic array) to hold list of sales people names (from file)

    if (argc > 1) {
        salesNames = getSalesNamesFromFile(argv[1]);
    }
    else{
        salesNames = getSalesNamesDefault();
    }

    map<string, double> salesRecords; // create map to hold {salespeople, total sales} pairs
    for (int i = 0; i < salesNames.size(); i++) {
        string salesPerson = salesNames[i];
        double salesAmt = getSalesAmt(salesPerson);
        salesRecords[salesPerson] = salesAmt;
    }

    findLowest(salesRecords);
}


// loops through salespeople and gets total amount of sales (user input)
double getSalesAmt(string name) {
    double amt = 0;
    while (amt <= 0) {
        string userInput = "";
        cout << "How much is the sales amount for: " << std::setw(10) << std::left << name << "$";
        cin >> userInput;
        double validatedInput = checkInput(userInput); // validates input to make sure a number is entered
        if (validatedInput) {
            amt = validatedInput;
            if (amt <= 0) {
                cout << "The sales amount must be a positive number.\n";
            }
        }
        else {
            cout << "Invalid input, please enter a number only.\n";
        }       
    }
    return amt;
}


// takes map (key=salesperson name, value=total sales) as argument
// instantiate iterator to loop through key-value pairs and check against lowest sale amount
void findLowest(const map<string, double> &salesRecords) {
    double lowestSaleAmt = std::numeric_limits<double>::max(); // set initial lowest sale amount to max double value
    string lowestSalesName = "";
    for (map<string, double>::const_iterator c_iter = salesRecords.begin(); c_iter != salesRecords.end(); c_iter++) {
        if (c_iter -> second < lowestSaleAmt) {
            lowestSaleAmt = c_iter -> second;
            lowestSalesName = c_iter -> first;
        }
        else if (c_iter -> second == lowestSaleAmt) {
            lowestSalesName += ", " + c_iter -> first;
        }
    }
    cout << std::fixed << std::showpoint << std::setprecision(2);
    cout << "\n" << lowestSalesName << " had the lowest number of reported sale(s) last year.\n\n";
    cout << lowestSalesName << "'s reported amount was $" << lowestSaleAmt << ".\n";
}


// get salespeople's names from file
vector<string> getSalesNamesFromFile(const char* filePath) {
    vector<string> salesNames; // create vector (dynamic array) to hold list of sales people names (from file)
    ifstream namesFile;
    namesFile.open(filePath);
    if (namesFile.fail()) {
        cout<<"Error opening file. Using default names list.\n";
        salesNames = getSalesNamesDefault();
    }
    else {
        string name = "";
        while (namesFile >> name) {
            salesNames.push_back(name);
        }
    }
    
    return salesNames;
}


// use default salespeople name list
vector<string> getSalesNamesDefault() {
    vector<string> namesList = {
        "David",
        "John",
        "Laura",
        "Andy",
        "Cathy"
    };

    return namesList;
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