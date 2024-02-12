#include <iostream>
#include <cstring>
using namespace std;

const int MAX_USER_INPUT = 100;

//define Contact structure here
struct Contact {
    char name[MAX_USER_INPUT];
    char phone_number[MAX_USER_INPUT];
};

//declare your sort() and binSearch() functions
void sort(Contact* contacts, int contactSize) {

}

void binSearch()

int main() {
    //your program goes here.
    int numOfContacts;
    cout << "Enter number of people: ";
    cin >> numOfContacts;
    Contact* contacts = new Contact[numOfContacts];
    
    for (int i = 0; i < numOfContacts; i++) {
        cout << "Enter contact name: ";
        cin.ignore();
        cin.getline(contacts[i].name, MAX_USER_INPUT);

        cout << "Enter contact number: ";
        cin.ignore();
        cin.getline(contacts[i].phone_number, MAX_USER_INPUT);
    }

    sort(contacts, numOfContacts);

    cout << "You entered " << contacts[0].name;

    delete(contacts);
    return 0;
}