#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::regex;
using std::regex_search;

void welcomeMsg();
void verifyPassword();
bool checkPassword(string);


// Main
int main() {
    welcomeMsg();
    verifyPassword();
    return 0;
}


// Display instructions
void welcomeMsg() {
    cout << "Password Requirements:\n";
    cout << "  - The password should be at least 9 characters long.\n";
    cout << "  - The password should contain at least one uppercase and at least one lowercase letter.\n";
    cout << "  - The password should have at least one digit and at least one special character (@ $ ! % # &).\n\n";
}


// Asks user for password and checks input
void verifyPassword() {
    cout << "Enter a password: ";
    string userInput = "";
    getline(cin, userInput);
    checkPassword(userInput);
}


// Validates password
bool checkPassword(string pw) {
    bool pwOK = true;
    if (!regex_search(pw, regex("[a-z]"))) {
        pwOK = false;
        cout << "It should contain at least one lowercase letter.\n";
    }
    if (!regex_search(pw, regex("[A-Z]"))) {
        pwOK = false;
        cout << "It should contain at least one uppercase letter.\n";
    } 
    if (!regex_search(pw, regex("[0-9]"))) {
        pwOK = false;
        cout << "It should contain at least one number.\n";
    }
    if (!regex_search(pw, regex("[:punct:]"))) {
        pwOK = false;
        cout << "It should contain at least one special character.\n";
    }

    if (pwOK) {
        return true;
    }
    else {
        verifyPassword();
    }
}