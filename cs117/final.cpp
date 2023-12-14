#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::map;

// Structs
struct OperatingCosts {
    float rent;
    float utilities;
    float supplies;
    float tax;
    float insurance;
    float misc;
};

// Prototypes
void defaultBudget(OperatingCosts*);
void budgetFromFile(OperatingCosts*, OperatingCosts*, ifstream*);
void initializeB_EMap(map<string, float>*, const vector<string>*);
float convertToFloat(string);
void getExpensesFromUser(OperatingCosts*);
void displayResults(OperatingCosts*, OperatingCosts*);


// Main
int main(int argc, char* argv[]) {
    OperatingCosts storeBudget; // Will hold budget for monthly store expenditures
    OperatingCosts storeExpenses; // Will hold actual monthly store expenditures

    if (argc > 1) {
        ifstream file(argv[1]);
        if (file) {
            budgetFromFile(&storeBudget, &storeExpenses, &file);
            file.close();
        }
        else {
            cout << "Could not read file provided, using default budget." << endl;
            defaultBudget(&storeBudget);
            getExpensesFromUser(&storeExpenses);
            displayResults(&storeBudget, &storeExpenses);
        }
    }
    else {
        defaultBudget(&storeBudget);
        getExpensesFromUser(&storeExpenses);
        displayResults(&storeBudget, &storeExpenses);
    }

    return 0;
}


// If no budget file is provided, will set this as default budget
void defaultBudget(OperatingCosts* storeBudget) {
    storeBudget->rent = 2000;
    storeBudget->utilities = 175;
    storeBudget->supplies = 7500;
    storeBudget->tax = 800;
    storeBudget->insurance = 350;
    storeBudget->misc = 400;
}


// Takes budget struct and file pointer
// Reads from file and inserts value if specified in file
// See budget.txt for format of budget file
void budgetFromFile(OperatingCosts* storeBudget, OperatingCosts* storeExpenses, ifstream* file) {
    // Arrays hold keywords to check for in file
    const vector<string> fileBudget = {"b_rent", "b_utilities", "b_supplies", "b_tax", "b_insurance", "b_miscellaneous"};
    const vector<string> fileExpense = {"e_rent", "e_utilities", "e_supplies", "e_tax", "e_insurance", "e_miscellaneous"};

    map<string, float> budgetMap;
    initializeB_EMap(&budgetMap, &fileBudget);
    map<string, float> expenseMap;
    initializeB_EMap(&expenseMap, &fileExpense);

    string line;
    while (getline(*file, line)) {
        string name = line.substr(0, line.find("="));
        for (map<string, float>::iterator iter = budgetMap.begin(); iter != budgetMap.end(); iter++) {
            if (iter->first.compare(name) == 0) {
                float convertedNum = convertToFloat(line.substr(line.find('=') + 1));
                if (convertedNum >= 0) {
                    iter->second = convertedNum;
                }
            }
        }
        for (map<string, float>::iterator iter = expenseMap.begin(); iter != expenseMap.end(); iter++) {
            if (iter->first.compare(name) == 0) {
                float convertedNum = convertToFloat(line.substr(line.find('=') + 1));
                if (convertedNum >= 0) {
                    iter->second = convertedNum;
                }
            }
        }
    }
    
    storeBudget->rent = budgetMap["b_rent"];
    storeBudget->utilities = budgetMap["b_utilities"];
    storeBudget->supplies = budgetMap["b_supplies"];
    storeBudget->tax = budgetMap["b_tax"];
    storeBudget->insurance = budgetMap["b_insurance"];
    storeBudget->misc = budgetMap["b_miscellaneous"];

    storeExpenses->rent = expenseMap["e_rent"];
    storeExpenses->utilities = expenseMap["e_utilities"];
    storeExpenses->supplies = expenseMap["e_supplies"];
    storeExpenses->tax = expenseMap["e_tax"];
    storeExpenses->insurance = expenseMap["e_insurance"];
    storeExpenses->misc = expenseMap["e_miscellaneous"];
}


// Asks user for expenses
void getExpensesFromUser(OperatingCosts* storeExpenses) {
    string val;
    cout << "Enter the amount spent for rent: $";
    getline(cin, val);
    storeExpenses->rent = convertToFloat(val);
    cout << "Enter the amount spent for utilities: $";
    getline(cin, val);
    storeExpenses->utilities = convertToFloat(val);
    cout << "Enter the amount spent for supplies: $";
    getline(cin, val);
    storeExpenses->supplies = convertToFloat(val);
    cout << "Enter the amount spent for tax: $";
    getline(cin, val);
    storeExpenses->tax = convertToFloat(val);
    cout << "Enter the amount spent for insurance: $";
    getline(cin, val);
    storeExpenses->insurance = convertToFloat(val);
    cout << "Enter the amount spent for miscellaneous: $";
    getline(cin, val);
    storeExpenses->misc = convertToFloat(val);
}


// Displays the results
void displayResults(OperatingCosts* storeBudget, OperatingCosts* storeExpenses) {
    float totalOverUnder = 0;

    cout << std::setw(20) << std::left << "Type of Expense";
    cout << std::setw(13) << std::left << "Budgeted"; 
    cout << std::setw(10) << std::left << "Spent";
    cout << "Over(-)/Under(+)" << endl;
    cout << string(59, '-') << endl;

    cout << std::fixed << std::setprecision(2);
    cout << std::setw(17) << std::left << "Rent";
    cout << std::setw(10) << std::right << storeBudget->rent; 
    cout << std::setw(12) << std::right << storeExpenses->rent;
    float overUnder = storeBudget->rent - storeExpenses->rent;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Utilities";
    cout << std::setw(10) << std::right << storeBudget->utilities; 
    cout << std::setw(12) << std::right << storeExpenses->utilities;
    overUnder = storeBudget->utilities - storeExpenses->utilities;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Supplies";
    cout << std::setw(10) << std::right << storeBudget->supplies; 
    cout << std::setw(12) << std::right << storeExpenses->supplies;
    overUnder = storeBudget->supplies - storeExpenses->supplies;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;
}

// Takes a map<string, float> and a pointer to a vector that holds map keys
// Initializes a budget or expense map with keys from vector and default value 0
void initializeB_EMap(map<string, float>* beMap, const vector<string>* values) {
    for (string name: *values) {
        beMap->insert({name, 0});
    }
}


// Attempts to convert string to float, returns -1 if fail
float convertToFloat(string num) {
    float convertedNum = 0;
    try {
        convertedNum = stof(num);
    }
    catch(...) {
        convertedNum = -1;
    }
    return convertedNum;
}