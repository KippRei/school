// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: Word Count

// Description: Asks user for input (C-String)
// Description: Prints the number of words in C-String

// Program Name submitted to Canvas: Reitzel_Marques_WordCount

#include <iostream>
#include <cstring>

// Better practice than 'using namespace std;'
using std::cout;
using std::cin;
using std::endl;
using std::strtok;
using std::getline;

int getNumberOfWords(char*);

const int C_STR_SIZE = 80;


// Main
int main() {
    char cStr[C_STR_SIZE];
    cout << "Enter a C-String containing 80 or fewer characters:" << endl;
    cin.getline(cStr, C_STR_SIZE);

    int numOfSpaces = getNumberOfWords(cStr);
    
    cout << "The number of words in the C-String: " << numOfSpaces << endl;
    return 0;
}


// Takes pointer to C-String and returns number of words in C-String
int getNumberOfWords(char* cStr) {
    char* wordInStr = strtok(cStr, " ");
    int counter = 0;

    while (wordInStr != NULL) {
        counter++;
        wordInStr = strtok(NULL, " ");
    }

    return counter;
}