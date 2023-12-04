// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: AdmittedPatients

// Description: Asks user for number of hospitals they would like to record quarterly admitted patient data for
// Description: Asks user to enter number of admitted patients for each quarter (for each hospital)
// Description: Displays total admitted patients (Q1-Q4) and quarterly average of admitted patients

// Program Name submitted to Canvas: Reitzel_Marques_AdmittedPatients


#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;


// Structs
struct HospitalInfo {
    // Hospital name
    string name;

    // Number of admitted patients each quarter
    int qtr1;
    int qtr2;
    int qtr3;
    int qtr4;

    // Returns total number of admitted patients (Q1-Q4)
    int getPatientTotal() {
        return (qtr1 + qtr2 + qtr3 + qtr4);
    }

    // Returns average number of patients admitted (quarterly)
    int getPatientAvg() {
        return ((qtr1 + qtr2 + qtr3 + qtr4) / 4);
    }
};


// Prototypes
HospitalInfo* getInfo();
void displayHospitalStats(HospitalInfo*);
string allUpper(string);
string abbreviateName(string);
int getNumberFromUser();


// Main
int main() {
    HospitalInfo* hospitals = getInfo();
    displayHospitalStats(hospitals);
    return 0;
}


// Get hospital information from user and return pointer HospitalInfo array
HospitalInfo* getInfo() {
    cout << "How many hospitals will you be entering information for?: ";
    int numOfHospitals = getNumberFromUser();
    if (numOfHospitals == 0) {
        cout << "No data to enter, exiting program.\n";
        std::exit(0);
    }

    // Using a sentinel HospitalInfo with name '__nullhsptl__' to indicate end of array
    HospitalInfo* hospitals = new HospitalInfo[numOfHospitals + 1];
    hospitals[numOfHospitals].name = "__nullhsptl__";

    // Loop through hospitals and get name and quarterly number of admitted patients for each hospital
    for (int i = 0; i < numOfHospitals; i++) {
        cout << std::endl;
        cout << "Name of Hospital #" << i+1 << ": ";
        string tempName;
        getline(cin, tempName);
        hospitals[i].name = allUpper(tempName);
        cout << "Enter the admitted patients for " << hospitals[i].name << ":\n";
        cout << std::setw(20) << std::left << "    First quarter: ";
        hospitals[i].qtr1 = getNumberFromUser();
        cout << std::setw(20) << std::left << "    Second quarter: ";
        hospitals[i].qtr2 = getNumberFromUser();
        cout << std::setw(20) << std::left << "    Third quarter: ";
        hospitals[i].qtr3 = getNumberFromUser();
        cout << std::setw(20) << std::left << "    Fourth quarter: ";
        hospitals[i].qtr4 = getNumberFromUser();
    }

    return hospitals;
}


// Display hospital patient admittance totals and averages
void displayHospitalStats(HospitalInfo* hospitals) {
    cout << "\nTotal admitted patients:\n";
    for (int i = 0; hospitals[i].name != "__nullhsptl__"; i++) {
        string abbrName = abbreviateName(hospitals[i].name); // Abbreviates name of hospital down to 20 characters (for better display)
        cout << "    " << abbrName << ": " << hospitals[i].getPatientTotal() << std::endl;
    }

    cout << "\nAverage number of admitted patients:\n";
    for (int i = 0; hospitals[i].name != "__nullhsptl__"; i++) {
        string abbrName = abbreviateName(hospitals[i].name); // Abbreviates name of hospital down to 20 characters (for better display)
        cout << "    " << abbrName << ": " << hospitals[i].getPatientAvg() << std::endl;
    }
}


// Takes string and returns all uppecase string
string allUpper(string str) {
    for (char& c: str) c = toupper(c);
    return str;
}


// Returns hospital name cut to max of 20 characters for better display purposes
string abbreviateName(string name) {
    int length = 20;
    if (name.size() < 20) length = name.size();
    return name.substr(0, length);
}


// Gets valid number from user (positive integer or 0)
int getNumberFromUser() {
    int validatedNum = -1;
    
    while (validatedNum < 0) {
        try {
            string userInput;
            getline(cin, userInput);
            size_t pos;
            validatedNum = std::stoi(userInput, &pos);
            if (pos < userInput.size()) {
                throw(userInput);
            }
            else if (validatedNum < 0) {
                throw(userInput);
            }
        }
        catch (...) {
            cout << "    Please enter a positive, whole number (or 0): ";
        }
    }

    return validatedNum;
}