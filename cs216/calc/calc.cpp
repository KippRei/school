#include <iostream>
#include "calc.h"
using namespace std;

// TODO: Define default constructor
Calculator::Calculator(): value(0){}
// TODO: Define member functions - 
//       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()
void Calculator::Add(double a) {
    value += a;
}

void Calculator::Subtract(double a) {
    value -= a;
}

void Calculator::Multiply(double a) {
    value *= a;
}

void Calculator::Divide(double a) {
    if (a != 0) {
        value /= a;
    }
    else {
        cout << "Cannot divide by zero" << endl;
    }
}

void Calculator::Clear() {
    value = 0;
}

double Calculator::GetValue() {
    return value;
}