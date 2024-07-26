// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: FindLowestSaleSimple.

// Description: Asks user for sales numbers of five people. Finds lowest sales and prints name and sales amount.

// Program Name submitted to Canvas: Reitzel_Marques_FindLowestSaleSimple

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double getSalesAmt(string);
void findLowest(double, double, double, double, double);

// Main
int main() {
  string david = "David";
  string john = "John";
  string laura = "Laura";
  string andy = "Andy";
  string cathy = "Cathy";
  double davidAmt = getSalesAmt(david);
  double johnAmt = getSalesAmt(john);
  double lauraAmt = getSalesAmt(laura);
  double andyAmt = getSalesAmt(andy);
  double cathyAmt = getSalesAmt(cathy);

  findLowest(davidAmt, johnAmt, lauraAmt, andyAmt, cathyAmt);
}

// Gets sales amount for each salesperson from user
double getSalesAmt(string salesName) {
  double amt = -1;
  while (amt < 0) {
    cout << "How much is the sales amount for: " << std::setw(10) << std::left
         << salesName << "$";
    cin >> amt;
    if (amt < 0)
      cout
          << "The sales amount must be a positive number.\n"; // User input must be positive number
  }
  return amt;
}

// Finds lowest sales amount and prints name of salesperson and amount
void findLowest(double davidAmt, double johnAmt, double lauraAmt,
                double andyAmt, double cathyAmt) {
  double lowest = davidAmt;
  string name = "David";
  if (johnAmt < lowest) {
    lowest = johnAmt;
    name = "John";
  }
  if (lauraAmt < lowest) {
    lowest = lauraAmt;
    name = "Laura";
  }
  if (andyAmt < lowest) {
    lowest = andyAmt;
    name = "Andy";
  }
  if (cathyAmt < lowest) {
    lowest = cathyAmt;
    name = "Cathy";
  }

  cout << std::fixed << std::showpoint << std::setprecision(2);
  cout << "\n"
       << name << " had the lowest number of reported sale(s) last year.\n\n";
  cout << name << "'s reported amount was $" << lowest << ".\n";
}