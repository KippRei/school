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
    bool swap;

    do {
        swap = false;

        for (int i = 0; i < contactSize - 1; i++) {
            Contact* contact1 = &contacts[i];
            Contact* contact2 = &contacts[i + 1];
            if (strcmp(contact1 -> name, contact2 -> name) > 0) {
                swap = true;
                Contact temp = contacts[i];
                contacts[i] = contacts[i + 1];
                contacts[i + 1] = temp;
            }
        }
    } while(swap);
}

int binSearch(Contact* contacts, int contactSize, char* searchName) {
    int low = 0;
    int high = contactSize;

    while (low < high) {
        int mid = (low + high - 1) / 2;

        if (strcmp(contacts[mid].name, searchName) == 0) {
            return mid;
        }

        if (strcmp(contacts[mid].name, searchName) > 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    //your program goes here.
    int numOfContacts;
    cout << "Enter number of people: ";
    cin >> numOfContacts;
    cin.ignore();
    Contact* contacts = new Contact[numOfContacts];
    
    for (int i = 0; i < numOfContacts; i++) {
        cout << "Enter contact name: ";
        cin.getline(contacts[i].name, MAX_USER_INPUT);
        
        cout << "Enter contact number: ";
        cin.getline(contacts[i].phone_number, MAX_USER_INPUT);
    }

    sort(contacts, numOfContacts);

    for (int i = 0; i < numOfContacts; i++) {
        cout << contacts[i].name << " - " << contacts[i].phone_number << endl;
    }

    char* nameToSearch;
    cout << "Enter name to search: ";
    cin.getline(nameToSearch, MAX_USER_INPUT);

    int foundContactIndex = binSearch(contacts, numOfContacts, nameToSearch);

    if (foundContactIndex >= 0) {
        cout << contacts[foundContactIndex].name << " " << contacts[foundContactIndex].phone_number << endl;
    }
    else {
        cout << "Contact not found." << endl;
    }

    delete(contacts);

    return 0;
}