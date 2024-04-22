#include <iostream>
using namespace std;

class ContactNode {
public:
   /* Declare member functions here */
   ContactNode(string, string);
   string GetName();
   string GetPhoneNumber();
   void InsertAfter(ContactNode*);
   ContactNode* GetNext();
   void SetNext(ContactNode*);
   void PrintContactNode();
   
private:
   /* Declare data members here */
   string contactName;
   string contactPhoneNumber;
   ContactNode* nextNodePtr;
};

/* Define member functions here */
ContactNode::ContactNode(string n, string p) {
    contactName = n;
    contactPhoneNumber = p;
    nextNodePtr = nullptr;
}

string ContactNode::GetName() {
    return contactName;
}

string ContactNode::GetPhoneNumber() {
    return contactPhoneNumber;
}

ContactNode* ContactNode::GetNext() {
    return nextNodePtr;
}

void ContactNode::SetNext(ContactNode* toSet) {
    nextNodePtr = toSet;
}

void ContactNode::PrintContactNode() {
    cout << "Name: " << contactName << endl;
    cout << "Phone number: " << contactPhoneNumber << endl;
}

void ContactNode::InsertAfter(ContactNode* newNode) {
    ContactNode* temp = nextNodePtr;
    nextNodePtr = newNode;
    newNode->SetNext(temp);
}

int main() {
   string p1,n1,p2,n2,p3,n3;
   getline(cin, p1);
   getline(cin, n1);
   getline(cin, p2);
   getline(cin, n2);
   getline(cin, p3);
   getline(cin, n3);
   cout << "Person 1: " << p1 << ", " << n1 << endl;
   cout << "Person 2: " << p2 << ", " << n2 << endl;
   cout << "Person 3: " << p3 << ", " << n3 << endl << endl;
   ContactNode* one = new ContactNode(p1, n1);
   ContactNode* two = new ContactNode(p2, n2);
   ContactNode* three = new ContactNode(p3, n3);
   one->InsertAfter(two);
   two->InsertAfter(three);

   ContactNode* curr;
   curr = one;
   cout << "CONTACT LIST" << endl;
   do {
    curr->PrintContactNode();
    curr = curr->GetNext();
    cout << endl;
   } while(curr != nullptr);

   
   return 0;
}