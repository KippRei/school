#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>
using namespace std;

class BankAccount {
   public:
      // TODO: Declare public member functions
      BankAccount(string newName, double chBalance, double sBalance);
      void SetName(string newName);
      string GetName();
      void SetChecking(double balance);
      double GetChecking();
      void SetSavings(double balance);
      double GetSavings();
      void DepositChecking(double amt);
      void DepositSavings(double amt);
      void WithdrawChecking(double amt);
      void WithdrawSavings(double amt);
      void TransferToSavings(double amt);
   
   private:
      // TODO: Declare private data members
      string custName;
      double savBal;
      double chkBal;
};

#endif