// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: FindLowestSale.

// Description: Using list of salespeople (default or from file), ask user for total yearly sales amount then compare and return the name and sales amount of the salesperson/salespeople with the lowest yearly sales.

// Usage: ./FindLowestSale
// Usage: ./FindLowestSale <salesperson names filepath>

// Program Name submitted to Canvas: Reitzel_Marques_FindLowestSale


#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <vector> 
#include <limits>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::ifstream;
using std::vector;

double getSalesAmt(string);
void findLowest(const map<string, double>&);
vector<string> getSalesNamesFromFile(const string);
vector<string> getSalesNamesDefault();
double stringToDouble(string);

int main(int argc, char *argv[]) {
    vector<string> salesNames; // create vector (dynamic array) to hold list of salespeople's names

    // if argc is >1 then the user has entered a filepath name for file that contains names of salespeople or -h for help
    if (argc > 1) {
      string arg1 = argv[1];
      
      if (arg1.compare("-h") == 0) {
        cout << "Usage: ./FindLowestSale\n";
        cout << "Usage: ./FindLowestSale <filename>\n";
        std::exit(0);
      }
      else {
        salesNames = getSalesNamesFromFile(arg1);
      }
    }
    else{
        salesNames = getSalesNamesDefault();
    }

    map<string, double> salesRecords; // create map to hold {salesperson name, total sales} pairs
    for (int i = 0; i < salesNames.size(); i++) {
        string salesPerson = salesNames[i];
        double salesAmt = getSalesAmt(salesPerson);
        salesRecords[salesPerson] = salesAmt;
    }

    findLowest(salesRecords);
}


// Loops through salespeople and gets total amount of sales (user input) and validates
double getSalesAmt(string name) {
    double amt = 0;
  
    while (amt <= 0) {
        string userInput = "";
        cout << "How much is the sales amount for: " << std::setw(10) << std::left << name << "$";
        getline(cin, userInput);
      
        double validatedInput = stringToDouble(userInput);
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


// Takes map (key=salesperson name, value=total sales) as argument
// Sets initial lowest sales amount to max double value
// Instantiate iterator to loop through key-value pairs and check against lowest sale amount
void findLowest(const map<string, double> &salesRecords) {
    double lowestSaleAmt = std::numeric_limits<double>::max();
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


// Get salespeople's names from file and put in vector (dynamic array)
// If file does not exist, return vector with default names
vector<string> getSalesNamesFromFile(const string filePath) {
    vector<string> salesNames;
  
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
  
    namesFile.close();
    return salesNames;
}


// Use default salespeople name list
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


// Checks user input to ensure valid input (must be a positive number)
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