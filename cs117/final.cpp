// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: Monthly Expense Calculator (Final)

// Description: Asks for monthly budget then expenditures
// Description: Calculates and displays amount over/under budget
// Description: Budget/Expense report can be saves as .csv

// Program Name submitted to Canvas: Reitzel_Marques_Final

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

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
const vector<string> FILE_BUDGET = {"b_rent", "b_utilities", "b_supplies", "b_tax", "b_insurance", "b_miscellaneous"};
const vector<string> FILE_EXPENSE = {"e_rent", "e_utilities", "e_supplies", "e_tax", "e_insurance", "e_miscellaneous"};

// Prototypes
string start();
void defaultBudget(OperatingCosts*);
void budgetFromFile(OperatingCosts*, OperatingCosts*, ifstream*);
void getExpensesFromUser(OperatingCosts*);
void displayResults(OperatingCosts*, OperatingCosts*);
void saveBudgetResults(OperatingCosts*, OperatingCosts*);
float getValidNum();
bool createBudgetFile(string);
string getDateTime();
void _initializeB_EMap(map<string, float>*, const vector<string>*);
float convertToFloat(string);


// Main
int main() {
    OperatingCosts storeBudget; // Will hold budget for monthly store expenditures
    OperatingCosts storeExpenses; // Will hold actual monthly store expenditures

    bool validFile = false; // Flag for whether or not budget/expense file could be opened (if provided)

    do {
        string filePath = start(); // start() displays welcome message and gets file name from user (optional)

        // If user provided file name, will attempt to open file
        if (filePath.size() > 0) {
            filePath = "./" + filePath;
            ifstream file(filePath);
            // If file is successfully opened read data from file into storeBudget and storeExpenses structs
            // Sets validFile flag to true to exit loop
            if (file) {
                cout << "Reading data from file..." << endl;
                budgetFromFile(&storeBudget, &storeExpenses, &file);
                file.close();
                validFile = true;
            }
            // If file cannot be opened display error message and loops back to start()
            else {
                cout << "Could not read file provided, please try again.\n" << endl;
            }
        }

        // If no file name is provided by user, will use default budget for storeBudget struct and ask user for storeExpenses values
        else {
            defaultBudget(&storeBudget);
            getExpensesFromUser(&storeExpenses);
            validFile = true;
        }
    } while (!validFile);

    // Once data is read into storeBudget and storeExpense structs, display the results
    displayResults(&storeBudget, &storeExpenses);

    // Ask user if they'd like to save the results as a CSV file (can be opened with Excel, Sheets, etc.)
    cout << "\nWould you like to save your report as a CSV file? (y/n): ";
    string userResponse;
    getline(cin, userResponse);
    if (userResponse[0] == 'Y' || userResponse[0] == 'y') {
        saveBudgetResults(&storeBudget, &storeExpenses);
    }

    return 0;
}



// Displays welcome message with program information and returns filepath if provided (returns empty string otherwise)
string start() {
    cout << "Welcome To Your Monthly Expense Calculator!" << endl;
    cout << "Here you can set your budget then enter your expenses to determine if you're over or under budget for the month.\n" << endl;
    cout << "If you'd like to use the default budget and enter your expenses manually, just press enter.\n";
    cout << "If you'd like to upload your budget and/or expenses from a file, enter the file path.\n";
    cout << "You can also type DFP to use the default file path (./budget.txt).\n";
    cout << "(If default file path does not exist a file will be created and you will be asked to input data).\n";
    cout << "Or type CREATE to create a new budget/expense file.\n";
    cout << "Input: ";
    string input = "";
    getline(cin, input);
    cout << endl;

    // Creates checkInput string to make an upper-case copy of user input for checking input
    string checkInput;
    for (char c: input) checkInput += toupper(c);

    string filePath = ""; // Created to hold name of file path

    // If DFP is entered, use default name for budget file (budget.txt)
    // This file will be created if it does not already exist
    if (checkInput == "DFP") {
        filePath = "budget.txt";
        fstream file(filePath);
        if (file) {
            file.close();
        }
        else {
            createBudgetFile(filePath);
        }
    }

    // If CREATE is entererd, user will be asked for a name to create new budget/expense file
    // Will loop until valid name is entered
    else if (checkInput == "CREATE") {
        bool validFile = false;
        do {
            cout << "Enter a name for this budget/expense file: ";
            getline(cin, filePath);
            filePath += ".txt";
            validFile = createBudgetFile(filePath);
        } while (!validFile);
    }

    // If user entered something other than DFP or CREATE, that will be set as file path for existing budget/expense file
    else if (input.size() > 0) filePath = input;

    return filePath;
}


// Creates a budget/expenses file returns true on success, false on fail
bool createBudgetFile(string filePath) {
    ofstream file;
    file.open(filePath); // Try to open file with name provided
    
    // If file is created successfully using name provided (filePath argument)
    // Asks user for data to create file
    if (file) {
        file << "(Budget)";
        for (string val: FILE_BUDGET) {
            file << "\n" << val << "=";
            val = val.substr(val.find('_') + 1);
            cout << "Please manually enter the budget for " << val << ": $";
            file << getValidNum();
        }

        file << "\n\n(Expenditures)";
        for (string val: FILE_EXPENSE) {
            file << "\n" << val << "=";
            val = val.substr(val.find('_') + 1);
            cout << "Please manually enter the amount spent on " << val << ": $";
            file << getValidNum();
        }
        file.close();
    }

    // If file is not created (most likely invalid characters in file name provided by user)
    else {
        cout << "\nError trying to create file.\n";
        return false;
    }
    return true;
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
// (See budget.txt for format of budget file)
void budgetFromFile(OperatingCosts* storeBudget, OperatingCosts* storeExpenses, ifstream* file) {
    // Create key-value map for budget and expense tracking
    // Will use FILE_BUDGET and FILE_EXPENSE global vectors for keys and set -1 for all values initially
    map<string, float> budgetMap;
    _initializeB_EMap(&budgetMap, &FILE_BUDGET);
    map<string, float> expenseMap;
    _initializeB_EMap(&expenseMap, &FILE_EXPENSE);

    // Will go line by line through budget/expense text file provided by user
    // Check tags in file against keys in budget and expense maps
    // If tag in file matches key in map, map value is set to value provided in file
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

    // If there are any budget values not provided in text file, this will ask for user to manually input budget value
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
    
    // If there are any expense values not provided in text file, this will ask for user to manually input expense value
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
    
    // Once budget and expense maps have been filled, populate storeBudget and storeExpense struct variables using corresponding values from maps
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
    float totalOverUnder = 0; // Holds total over/under value for display at end
    float totalBudget = 0; // Holds total budget value for display at end
    float totalExpenses = 0; // Holds total budget value for display at end

    cout << endl;
    cout << std::setw(20) << std::left << "Type of Expense";
    cout << std::setw(13) << std::left << "Budgeted"; 
    cout << std::setw(10) << std::left << "Spent";
    cout << "Over(-)/Under(+)" << endl;
    cout << string(59, '-') << endl; // Creates underline

    cout << std::fixed << std::setprecision(2);
    cout << std::setw(17) << std::left << "Rent";
    cout << std::setw(10) << std::right << storeBudget->rent; 
    cout << std::setw(12) << std::right << storeExpenses->rent;
    float overUnder = storeBudget->rent - storeExpenses->rent;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->rent;
    totalExpenses += storeExpenses->rent;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Utilities";
    cout << std::setw(10) << std::right << storeBudget->utilities; 
    cout << std::setw(12) << std::right << storeExpenses->utilities;
    overUnder = storeBudget->utilities - storeExpenses->utilities;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->utilities;
    totalExpenses += storeExpenses->utilities;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Supplies";
    cout << std::setw(10) << std::right << storeBudget->supplies; 
    cout << std::setw(12) << std::right << storeExpenses->supplies;
    overUnder = storeBudget->supplies - storeExpenses->supplies;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->supplies;
    totalExpenses += storeExpenses->supplies;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Tax";
    cout << std::setw(10) << std::right << storeBudget->tax; 
    cout << std::setw(12) << std::right << storeExpenses->tax;
    overUnder = storeBudget->tax - storeExpenses->tax;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->tax;
    totalExpenses += storeExpenses->tax;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Insurance";
    cout << std::setw(10) << std::right << storeBudget->insurance; 
    cout << std::setw(12) << std::right << storeExpenses->insurance;
    overUnder = storeBudget->insurance - storeExpenses->insurance;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->insurance;
    totalExpenses += storeExpenses->insurance;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Miscellaneous";
    cout << std::setw(10) << std::right << storeBudget->misc; 
    cout << std::setw(12) << std::right << storeExpenses->misc;
    overUnder = storeBudget->misc - storeExpenses->misc;
    totalOverUnder += overUnder;
    totalBudget += storeBudget->misc;
    totalExpenses += storeExpenses->misc;
    cout << std::setw(15) << std::right << overUnder << endl;

    cout << std::setw(17) << std::left << "Total";
    cout << std::setw(10) << std::right << totalBudget; 
    cout << std::setw(12) << std::right << totalExpenses;
    cout << std::setw(15) << std::right << totalOverUnder << endl;

    if (totalOverUnder > 0) {
        cout << "For the month, you are under budget by $" << totalOverUnder << endl;
    }
    else if (totalOverUnder < 0) {
        cout << "For the month, you are over budget by -$" << -totalOverUnder << endl;
    }
    else {
        cout << "For the month you are right on budget." << endl;
    }
}


// Ask user if they'd like to save the results
// If yes, create a CSV file of results (for Excel/Sheets)
void saveBudgetResults(OperatingCosts* storeBudget, OperatingCosts* storeExpenses) {
    string fileName;
    ofstream file;
    bool validFileName = false;
    
    // Asks user to enter file name to save report as CSV file (or press enter for default name)
    // Will loop until valid file name is entered (i.e. until a new file is created successfully)
    do {
        cout << "Enter a name for this budget report file or press enter to use default, timestamped name: ";
        getline(cin, fileName);
        // If user enters file name, try to create file with that name
        if (fileName != "") {
            fileName += ".csv";
            file.open(fileName);
            if (!file) {
                cout << "\nI'm sorry that is not a valid file name.\n";
                cout << "Please try again.\n\n";
            }
            else {
                validFileName = true;
            }
        }

        // If user doesn't enter a file name (just presses enter) create a new file with default name
        // (default report file name is: Budget_Report_[date and time].csv)
        else {
            string timeToAppend = getDateTime();
            fileName = "Budget_Report_" + timeToAppend + ".csv";
            file.open(fileName);
            validFileName = true;
        }
    } while (!validFileName);

    // Similar to displayResults, this will go through the budget and expense structs and save values to file in CSV format
    float totalOverUnder = 0;
    float totalBudget = 0;
    float totalExpenses = 0;

    file << std::fixed;
    file << std::setprecision(2);
    file << "Type of Expense, Budgeted, Spent, Over(-)/Under(+)\n";

    file << "Rent, " << storeBudget->rent << ", " << storeExpenses->rent << ", " << storeBudget->rent - storeExpenses->rent << endl;
    totalOverUnder += storeBudget->rent - storeExpenses->rent;
    totalBudget += storeBudget->rent;
    totalExpenses += storeExpenses->rent;
    
    file << "Utilities, " << storeBudget->utilities << ", " << storeExpenses->utilities << ", " << storeBudget->utilities - storeExpenses->utilities << endl;
    totalOverUnder += storeBudget->utilities - storeExpenses->utilities;
    totalBudget += storeBudget->utilities;
    totalExpenses += storeExpenses->utilities;

    file << "Supplies, " << storeBudget->supplies << ", " << storeExpenses->supplies << ", " << storeBudget->supplies - storeExpenses->supplies << endl;
    totalOverUnder += storeBudget->supplies - storeExpenses->supplies;
    totalBudget += storeBudget->supplies;
    totalExpenses += storeExpenses->supplies;

    file << "Tax, " << storeBudget->tax << ", " << storeExpenses->tax << ", " << storeBudget->tax - storeExpenses->tax << endl;
    totalOverUnder += storeBudget->tax - storeExpenses->tax;
    totalBudget += storeBudget->tax;
    totalExpenses += storeExpenses->tax;
    
    file << "Insurance, " << storeBudget->insurance << ", " << storeExpenses->insurance << ", " << storeBudget->insurance - storeExpenses->insurance << endl;
    totalOverUnder += storeBudget->insurance - storeExpenses->insurance;
    totalBudget += storeBudget->insurance;
    totalExpenses += storeExpenses->insurance;
    
    file << "Miscellaneous, " << storeBudget->misc << ", " << storeExpenses->misc << ", " << storeBudget->misc - storeExpenses->misc << endl;
    totalOverUnder += storeBudget->misc - storeExpenses->misc;
    totalBudget += storeBudget->misc;
    totalExpenses += storeExpenses->misc;

    file << "Total, " << totalBudget << ", " << totalExpenses << ", " << totalOverUnder;
    file.close();
}

// Takes a map<string, float> and a pointer to a vector that holds map keys
// Initializes a budget or expense map with keys from vector and default value -1
// (key names can be found in global vectors FILE_BUDGET and FILE_EXPENSE)
void _initializeB_EMap(map<string, float>* beMap, const vector<string>* values) {
    for (string name: *values) {
        beMap->insert({name, -1});
    }
}


// Returns time as string in format mm-dd-yyyy_hh-mm-ss
// Used by saveBudgetResults if default budget report file name is used
// (i.e. this will be appended to Budget_Report_ to create unique file name)
string getDateTime() {
    time_t currTime = time(0);
    tm* tmst = localtime(&currTime); // tmst = tm structure
    string timeToAppend = "";
    timeToAppend += std::to_string(tmst->tm_mon + 1);
    timeToAppend += "-";
    timeToAppend += std::to_string(tmst->tm_mday);
    timeToAppend += "-";
    timeToAppend += std::to_string(tmst->tm_year + 1900);
    timeToAppend += "_";
    timeToAppend += std::to_string(tmst->tm_hour);
    timeToAppend += "-";
    timeToAppend += std::to_string(tmst->tm_min);
    timeToAppend += "-";
    timeToAppend += std::to_string(tmst->tm_sec);

    return timeToAppend;
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


// Attempts to convert string to float, returns -1 if it fails
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