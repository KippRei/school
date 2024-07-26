#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::string;
using std::stoi;
using std::getline;
using std::cout;

// Prototypes
ifstream openFile(string);
void countNumbers(ifstream*);
int convertToInt(string);
void displayResults(int, int);


// Main
int main(int argc, char* argv[]) {
    // Default filepath is Randome.txt
    string filePath = "./Randome.txt";
    // If user enters a second argument, program will use that as filepath
    if (argc > 1) {
        filePath = argv[1];
    }

    // Attempt to open file
    ifstream file;
    file.open(filePath);

    // If file opens, count, sum, and average numbers in file (by line)
    // If file doesn't open, display error message
    if (file.is_open()) {
        countNumbers(&file);
        file.close();
    }
    else {
        cout << "Cannot open file.\n";
    }

    return 0;
}


// Takes pointer to ifstream and goes through file line-by-line adding numbers and counting number of numbers
// If line does not contain a number only, function skips the line
void countNumbers(ifstream* file) {
    string line = "";
    int count = 0;
    int sum = 0;

    while(getline(*file, line)) {
        int number = convertToInt(line);
        if (number) {
            sum += convertToInt(line);
            count++;
        }
    }

    displayResults(sum, count);
}


// Displays results after file has been parsed to end
void displayResults(int sum, int count) {
    cout << "Number of numbers: " << count << std::endl;
    cout << "Sum of numbers: " << sum << std::endl;
    float fsum = static_cast<float>(sum);
    float fcount = static_cast<float>(count);
    float average = fsum / fcount;
    cout << "Average of the numbers: " << average << std::endl;
}


// Attempts to convert line (from countNumbers()) to number, returns 0 if operation fails
int convertToInt(string toConvert) {
    int convertedNum = 0;
    try {
        convertedNum = stoi(toConvert);
    }
    catch(...) {
    }
    return convertedNum;
}