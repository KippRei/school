// Introductory comments: Marques Kipp Reitzel, CS 117, Sections 17136 & 17137

// Program name: HOAFees.

// Description: Calculating HOA Fees for the next 10 years with a .01 percent
// increase and an initial charge of $275.00

// Program Name submitted to Canvas: Reitzel_Marques_HOAFees

#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
  // Variables and consts
  const int yearsProjected = 10;
  const float feePercentIncrease = .01;
  const float origMemberFee = 275.00;
  float memberFeeIncrease = 1.01;
  float currMemberFee = 275.00;

  // Chart heading
  std::cout << "Year    Increase    Amount\n"
            << "===========================\n";

  // Loops {yearsProjected} # of times and displays
  for (int i = 0; i < yearsProjected; i++) {
    // Calculate the increased member fee
    currMemberFee = origMemberFee * memberFeeIncrease;

    // inc is used for year and percent increase
    int inc = i + 1;

    // used to stringstream to concat number with percent sign for proper
    // display
    std::stringstream percentInc;
    percentInc << i + 1 << "%";

    // Display the year, percent increase, and amount
    std::cout << std::endl;
    std::cout << std::setw(8) << std::left << inc;
    std::cout << std::setw(12) << std::left << percentInc.str();
    std::cout << std::fixed << std::setprecision(2) << "$" << currMemberFee
              << std::endl;

    // Increase the percentage used to calculate member fee for next year
    memberFeeIncrease += feePercentIncrease;
  }
}