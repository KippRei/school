#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/* Define your function here */ 
double StepsToMiles(int steps) {
    if (steps < 0) {
        throw runtime_error("Exception: Negative step count entered.");
    }
    else {
    double miles = (double)steps/2000;
    return miles;
    }
}

int main() {

   /* Type your code here. */
   int steps;
    cin >> steps;
   try {
    cout << fixed << setprecision(2);
    cout << StepsToMiles(steps) << endl;
   } catch (runtime_error err) {
    cout << err.what() << endl;
   }

   return 0;
}