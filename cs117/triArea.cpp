#include <iostream>

using std::cout;
using std::endl;
using std::cin;

double getHeight();
double getBase();
double getArea(double h, double b);

int main() {
    double height = getHeight();
    double base = getBase();
    cout << getArea(height, base);
}

double getHeight() {
    double height;
    cout << "Enter height: " << endl;
    cin >> height;
    return height;
}

double getBase() {
    double base;
    cout << "Enter base: " << endl;
    cin >> base;
    return base;
}

double getArea(double h, double b) {
    return (h * b * .5);
}