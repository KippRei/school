// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: PasswordVerify

// Description: Asks user for password
// Description: Checks user password to ensure it meets password requirements
// Description: [Requirements: 9 or more characters including uppercase, lowercase, number, and special character(s)]

// Program Name submitted to Canvas: Reitzel_Marques_WordCount


#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void welcomeMsg();
void validateUserPassword();
string getUserInput();
bool verifyPassword(string);


// Main
int main() {
    welcomeMsg();
    validateUserPassword();
    return 0;
}


// Display instructions
void welcomeMsg() {
    cout << "Password Requirements:\n";
    cout << "  - The password should be at least 9 characters long.\n";
    cout << "  - The password should contain at least one uppercase and at least one lowercase letter.\n";
    cout << "  - The password should have at least one digit and at least one special character (@ $ ! % # &).\n\n";
}


// Asks for password from user and checks to ensure password meets requirements
void validateUserPassword() {
    bool verifiedPW = false;
    while (!verifiedPW) {
        string pw = getUserInput();
        verifiedPW = verifyPassword(pw);
    }
}


// Asks user for password and checks input
string getUserInput() {
    cout << "Enter a password: ";
    string userInput = "";
    getline(cin, userInput);
    return userInput;
}


// Check user input
bool verifyPassword(string pw) {
    bool strLenOK = false;
    bool upperChar = false;
    bool lwrChar = false;
    bool punctChar = false;
    bool digitChar = false;

    if (pw.length() >= 9) {
        strLenOK = true;
    }

    for(char c : pw) {
        if (isupper(c)) {
            upperChar = true;
        }
        else if (islower(c)) {
            lwrChar = true;
        }
        else if (isdigit(c)) {
            digitChar = true;
        }
        else if (ispunct(c)) {
            punctChar = true;
        }
    }

    if (strLenOK && upperChar && lwrChar && digitChar && punctChar) {
        cout << "The password is valid.\n";
        return true;
    }
    else {
        cout << "The password is invalid.\n";
        if (!strLenOK) {
            cout << "It should be at least 9 characters long.\n";
        }
        if (!upperChar) {
            cout << "It should contain at least one uppercase letter.\n";
        }
        if (!lwrChar) {
            cout << "It should contain at least one lowercase letter.\n";
        }
        if (!digitChar) {
            cout << "It should have at least one digit.\n";
        }
        if (!punctChar) {
            cout << "It should have at least one special character.\n";
        }
        return false;
    }
}