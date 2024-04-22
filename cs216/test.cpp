#include <iostream>
using namespace std;

class MyClass {
  public:
     MyClass() {
        cout << "Constructor called." << endl;
        dataObject = new int; // Allocate data object
        *dataObject = 0;
     }
    //  ~MyClass() {
    //     cout << "Destructor called." << endl;
    //     delete dataObject;
    //  }
     void SetDataObject(const int i) { *dataObject = i; }
     int GetDataObject() const { return *dataObject; }

  private:
     int* dataObject;
};

void SomeFunction(MyClass localObject) {
  // Do something with localObject
}

int main() {
  MyClass tempClassObject; // Create object of type MyClass
 
  // Set and print data member value
  tempClassObject.SetDataObject(9);
  cout << "Before: " << tempClassObject.GetDataObject() << endl;
 
  // Calls SomeFunction(), tempClassObject is passed by value
  SomeFunction(tempClassObject);          
 
  cout << "After: " << tempClassObject.GetDataObject() << endl;

  return 0;
}