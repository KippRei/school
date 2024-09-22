// Reitzel, Kipp        CS130 Section 15554  9/24/24
// First Laboratory Assignment - Bitwise Operation Calculator
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void calculate(char);
unsigned long long* getValidNumbers();

enum operators {
    AND = '&',
    OR = '|',
    XOR = '^',
    NOT = '~',
    NEGATE = '-',
    LEFTSHIFT = '<',
    RIGHTSHIFT = '>',
    STOP = '#'
};

int main() {
    cout << "Bitwise Operation Calculator - CS130 - 64 bits - Kipp Reitzel\n\n";
    string operation;

    while (true) {
        // Get user operation input
        cout << "Enter one of the following choices:"
                "\n& - AND"
                "\n| - OR"
                "\n^ - XOR"
                "\n~ - NOT"
                "\n- - Negate"
                "\n< - Left shift (logical shift only)"
                "\n> - Right shift (logical shift only)"
                "\n# - stop execution\n";
        getline(cin, operation);

        // If user operation input is more than one character, it is an inavlid input
        if (operation.length() > 1) {
            cout << "\nInvalid choice " << operation << ". Please try again.\n";
            continue;
        }

        // Changes user input to char for switch statement comparison
        char oper = operation[0];
        
        // Check user operation input
        switch (oper) {
            case AND:
            case OR:
            case XOR:
            case NOT:
            case NEGATE:
            case LEFTSHIFT:
            case RIGHTSHIFT:
                calculate(oper);
                break;

            case STOP:
                cout << "\nCalculation ended.\n";
                return 0;

            default:
                cout << "\nInvalid choice " << operation << ". Please try again.\n";
                continue;
        }
    }
    
    return 0;
}

void calculate(char oper) {
    unsigned long long* values = getValidNumbers();
    long unsigned result;

    switch (oper) {
        case AND:
            result = values[0] & values[1];
            break;

        case OR:
            result = values[0] | values[1];
            break;

        case XOR:
            result = values[0] ^ values[1];
            break;

        case NOT:
            result = ~values[0];
            break;

        case NEGATE:
            result = -values[0];
            break;

        case LEFTSHIFT:
            if (values[0] > sizeof(values[1])) {
                cout << "Shift value " << values[0] << " exceeds bit size " << sizeof(values[1]) << " - setting result to zero.\n";
                values[0] = 0;
                values[1] = 0;
            }
            result = values[0] < values[1];
            break;

        case RIGHTSHIFT:
            if (values[0] > sizeof(values[1])) {
                cout << "Shift value " << values[0] << " exceeds bit size " << sizeof(values[1]) << " - setting result to zero.\n";
                values[0] = 0;
                values[1] = 0;
            }
            result = values[0] > values[1];
            break;
    }
    
    cout << "\nResult:" << setw(8) << right << setfill(' ') << dec << result << " [Hexadecimal: " << setw(8) << right << setfill('0') << hex << result << "]\n";
}

unsigned long long* getValidNumbers() {
    bool validInput = false;
    string input1, input2;
    unsigned long long* values = new unsigned long long[2];

    while(validInput == false) {
        cout << "\nEnter values for first and second operand:\n";
        cin >> input1;
        cin >> input2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        try {
            if (input1[0] == '-' || input2[0] == '-') {
                throw ("negative");
            }
            else {
                values[0] = stoull(input1, NULL, 0);
                values[1] = stoull(input2, NULL, 0);
                validInput = true;
            }
        }
        catch (...) {
            cout << "\nInvalid value(s). Please try again.\n";
        }
    }

    return values;
}