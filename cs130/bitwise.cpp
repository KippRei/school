// Reitzel, Kipp        CS130 Section 15554  9/24/24
// First Laboratory Assignment - Bitwise Operation Calculator
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#define BYTE_SIZE 8;

bool calculate(std::string, unsigned long long*);
void getTwoNumbers(unsigned long long*);
void getOneNumber(unsigned long long*);

// Used for switch statement
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
    // Create array for holding operands
    unsigned long long* values = new unsigned long long[2];
    // Bit size of operands
    unsigned int operandSize = sizeof(values[0]) * BYTE_SIZE;

    // Display title
    std::cout << "Bitwise Operation Calculator - CS130 - " << operandSize << " bits - Kipp Reitzel\n\n";
    
    // String for holding operation selection and bool for while loop
    std::string operation;
    bool running = true;

    // Program runs until user selects '#' (which assigns false to 'running' variable)
    while (running) {
        // Get user operation input
        std::cout << "Enter one of the following choices:"
                "\n& - AND"
                "\n| - OR"
                "\n^ - XOR"
                "\n~ - NOT"
                "\n- - Negate"
                "\n< - Left shift (logical shift only)"
                "\n> - Right shift (logical shift only)"
                "\n# - stop execution\n";
        std::getline(std::cin, operation);

        running = calculate(operation, values);
    }
    
    delete [] values;
    return 0;
}

// Takes user operation input and attempts to calculate result
// If user selects '#' returns false, otherwise returns true
bool calculate(std::string operation, unsigned long long* values) {
    // If user operation input is more than one character, it is an inavlid input
    if (operation.length() > 1) {
        std::cout << "\nInvalid choice " << operation << ". Please try again.\n";
        return true;
    }

    // Changes user input to char for switch statement comparison
    char oper = operation[0];
        
    unsigned long long result;
    unsigned int operandSize = sizeof(values[0]) * BYTE_SIZE;

    switch (oper) {
        case AND:
            getTwoNumbers(values);
            result = values[0] & values[1];
            break;

        case OR:
            getTwoNumbers(values);
            result = values[0] | values[1];
            break;

        case XOR:
            getTwoNumbers(values);
            result = values[0] ^ values[1];
            break;

        case NOT:
            getOneNumber(values);
            result = ~values[0];
            break;

        case NEGATE:
            getOneNumber(values);
            result = -values[0];
            break;

        case LEFTSHIFT:
            getTwoNumbers(values);
            if (values[1] > operandSize) {
                std::cout << "\nShift value " << std::dec << values[1] << " exceeds bit size " << operandSize << " - setting result to zero.";
                values[0] = 0;
                values[1] = 0;
            }
            result = values[0] << values[1];
            break;

        case RIGHTSHIFT:
            getTwoNumbers(values);
            if (values[1] > operandSize) {
                std::cout << "\nShift value " << std::dec << values[1] << " exceeds bit size " << operandSize << " - setting result to zero.";
                values[0] = 0;
                values[1] = 0;
            }
            result = values[0] >> values[1];
            break;

        case STOP:
            std::cout << "\nCalculation ended.\n";
            return false;

        default:
            std::cout << "\nInvalid choice " << operation << ". Please try again." << std::endl;
            return true;
    }
    
    std::cout << "\nResult:" << std::dec << result << " [Hexadecimal: " << std::setw(sizeof(unsigned long long) * 2) << std::right << std::setfill('0') << std::hex << result << "]\n";
    return true;
}

// Gets two valid numbers from user and stores in 'values' array
void getTwoNumbers(unsigned long long* values) {
    bool validInput = false;
    std::string input1, input2;

    while(validInput == false) {
        std::cout << "\nEnter values for first and second operand:\n";
        std::cin >> input1;
        std::cin >> input2;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            if (input1[0] == '-' || input2[0] == '-') {
                throw ("negative");
            }
            else {
                values[0] = std::stoull(input1, NULL, 0);
                values[1] = std::stoull(input2, NULL, 0);
                validInput = true;
            }
        }
        catch (...) {
            std::cout << "\nInvalid value(s). Please try again.\n";
        }
    }
}

// Gets one valid number from user and stores at values[0]
void getOneNumber(unsigned long long* values) {
    bool validInput = false;
    std::string input1;

    while(validInput == false) {
        std::cout << "\nEnter value for operand:\n";
        std::cin >> input1;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            if (input1[0] == '-') {
                throw ("negative");
            }
            else {
                values[0] = std::stoull(input1, NULL, 0);
                validInput = true;
            }
        }
        catch (...) {
            std::cout << "\nInvalid value. Please try again.\n";
        }
    }
}