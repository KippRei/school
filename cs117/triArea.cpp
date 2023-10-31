#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

double getHeight();
double getBase();
double getArea(double h, double b);
void displayData( double h, double b, double a);

int main() {
    double base = getBase();
    double height = getHeight();
    double area = getArea(height, base);
    displayData(height, base, area);
}

double getHeight() {
    double height;
    cout << "Enter height: ";
    cin >> height;
    return height;
}

double getBase() {
    double base;
    cout << "Enter base: ";
    cin >> base;
    return base;
}

double getArea(double h, double b) {
    return (h * b * .5);
}

void displayData( double h, double b, double a) {
    // TODO: set precision to 2 dp
    int rwidth = 12;
    cout << endl;
    cout << "    Triangle's Area" << endl;
    cout << "-----------------------" << endl;
    cout << setw(10) << std::left << " Base: " << std::fixed << std::setprecision(2) << setw(rwidth) << std::right << b << endl;
    cout << setw(10) << std::left << " Height: " << std::fixed << std::setprecision(2) << setw(rwidth) << std::right << h << endl;
    cout << setw(10) << std::left << " Area: " << std::fixed << std::setprecision(2) << setw(rwidth) << std::right << a << endl;
    cout << endl;
}