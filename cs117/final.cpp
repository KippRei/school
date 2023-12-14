#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using std::ifstream;
using std::ofstream;
using std::fstream;
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

// Arrays hold keywords for budget file creation/parsing
const vector<string> fileBudget = {"b_rent", "b_utilities", "b_supplies", "b_tax", "b_insurance", "b_miscellaneous"};
const vector<string> fileExpense = {"e_rent", "e_utilities", "e_supplies", "e_tax", "e_insurance", "e_miscellaneous"};

// Prototypes
string start();
void defaultBudget(OperatingCosts*);
void budgetFromFile(OperatingCosts*, OperatingCosts*, ifstream*);
void getExpensesFromUser(OperatingCosts*);
void displayResults(OperatingCosts*, OperatingCosts*);
float getValidNum();
void createDefaultBudgetFile(string);
void initializeB_EMap(map<string, float>*, const vector<string>*);
float convertToFloat(string);


// Main
int main() {
    OperatingCosts storeBudget; // Will hold budget for monthly store expenditures
    OperatingCosts storeExpenses; // Will hold actual monthly store expenditures

    bool validFile = false; // Flag for whether or not budget/expense file could be opened (if provided)

    do {
        string filePath = start();

        if (filePath.size() > 0) {
            ifstream file(filePath);
            if (file) {
                cout << "Reading data from file..." << endl;
                budgetFromFile(&storeBudget, &storeExpenses, &file);
                file.close();
                validFile = true;
            }
            else {
                cout << "Could not read file provided, please try again.\n" << endl;
            }
        }
        else {
            defaultBudget(&storeBudget);
            getExpensesFromUser(&storeExpenses);
            validFile = true;
        }
    } while (!validFile);

    displayResults(&storeBudget, &storeExpenses);

    return 0;
}



// Displays welcome message with program information and returns filepath if provided (returns empty string otherwise)
string start() {
    cout << "Welcome To Your Monthly Expense Calculator" << endl;
    cout << "Here you can set your budget then enter your expenses to determine if you're over or under budget for the month" << endl;
    cout << "If you'd like to use the default budget and enter your expenses manually, just press enter.\n";
    cout << "If you'd like to upload your budget and/or expenses from a file, enter the filepath.\n";
    cout << "You can also type dfp to use the default filepath (./budget.txt).\n";
    cout << "(If default filepath does not exist a file will be created and you will be asked to input data).\n";
    cout << "Input: ";
    string input = "";
    getline(cin, input);
    cout << endl;

    string checkDefault;
    for (char c: input) checkDefault += toupper(c);

    string filePath = "";
    if (checkDefault == "DFP") {
        filePath = "./budget.txt";
        fstream file(filePath);
        if (file) {
            file.close();
        }
        else {
            createDefaultBudgetFile(filePath);
        }
    }
    else if (input.size() > 0) filePath = input;

    return filePath;
}


// Creates a default budget.txt file
void createDefaultBudgetFile(string filePath) {
    ofstream file;
    file.open(filePath);
    file << "(Budget)";
    for (string val: fileBudget) {
        file << "\n" << val << "=";
        val = val.substr(val.find('_') + 1);
        cout << "Please manually enter the budget for " << val << ": $";
        file << getValidNum();
    }

    file << "\n\n(Expenditures)";
    for (string val: fileExpense) {
        file << "\n" << val << "=";
        val = val.substr(val.find('_') + 1);
        cout << "Please manually enter the amount spent on " << val << ": $";
        file << getValidNum();
    }
    file.close();
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

    for (map<string, float>::iterator iter = budgetMap.begin(); iter != budgetMap.end(); iter++) {
        if (iter->second < 0) {
            float num = -1;
            while (num < 0) {
                string item = iter->first;
                item = item.substr(item.find('_') + 1);
                cout << "Please manually enter the budget for " << item << ": $";
                num = getValidNum();
            }
            iter->second = num;
        }
    }
    
    for (map<string, float>::iterator iter = expenseMap.begin(); iter != expenseMap.end(); iter++) {
        if (iter->second < 0) {
            float num = -1;
            while (num < 0) {
                string item = iter->first;
                item = item.substr(item.find('_') + 1);
                cout << "Please manually enter the amount spent on " << item << ": $";
                num = getValidNum();
            }
            iter->second = num;
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
    storeExpenses->rent = getValidNum();
    cout << "Enter the amount spent for utilities: $";
    storeExpenses->utilities = getValidNum();
    cout << "Enter the amount spent for supplies: $";
    storeExpenses->supplies = getValidNum();
    cout << "Enter the amount spent for tax: $";
    storeExpenses->tax = getValidNum();
    cout << "Enter the amount spent for insurance: $";
    storeExpenses->insurance = getValidNum();
    cout << "Enter the amount spent for miscellaneous: $";
    storeExpenses->misc = getValidNum();
}


// Displays the results
void displayResults(OperatingCosts* storeBudget, OperatingCosts* storeExpenses) {
    float totalOverUnder = 0;

    cout << endl;
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

    cout << std::setw(17) << std::left << "Tax";
    cout << std::setw(10) << std::right << storeBudget->tax; 
    cout << std::setw(12) << std::right << storeExpenses->tax;
    overUnder = storeBudget->tax - storeExpenses->tax;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Insurance";
    cout << std::setw(10) << std::right << storeBudget->insurance; 
    cout << std::setw(12) << std::right << storeExpenses->insurance;
    overUnder = storeBudget->insurance - storeExpenses->insurance;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Miscellaneous";
    cout << std::setw(10) << std::right << storeBudget->misc; 
    cout << std::setw(12) << std::right << storeExpenses->misc;
    overUnder = storeBudget->misc - storeExpenses->misc;
    totalOverUnder += overUnder;
    cout << std::setw(15) << std::right << overUnder << endl;

    if (totalOverUnder > 0) {
        cout << "For the month you are under budget by $" << totalOverUnder << endl;
    }
    else if (totalOverUnder < 0) {
        cout << "For the month you are over budget by -$" << -totalOverUnder << endl;
    }
    else {
        cout << "For the month you are right on budget." << endl;
    }
}


// Gets valid number from user
float getValidNum() {
    string val;
    float num = -1;
    while (num < 0) {
        getline(cin, val);
        num = convertToFloat(val);
        if (num < 0) cout << "Please enter a number value 0 or greater: $";
    }

    return num;
}

// Takes a map<string, float> and a pointer to a vector that holds map keys
// Initializes a budget or expense map with keys from vector and default value 0
void initializeB_EMap(map<string, float>* beMap, const vector<string>* values) {
    for (string name: *values) {
        beMap->insert({name, -1});
    }
}


// Attempts to convert string to float, returns -1 if fail
float convertToFloat(string num) {
    float convertedNum = 0;
    size_t index;
    try {
        convertedNum = stof(num, &index);
        if (index != num.size()) {
            throw(index);
        }
    }
    catch(...) {
        convertedNum = -1;
    }
    return convertedNum;
}