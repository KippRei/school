#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

int main() {
   BankAccount account("Mickey", 500.00, 1000.00);
   account.SetChecking(500);
   account.SetSavings(500);
   account.WithdrawSavings(100);
   account.WithdrawChecking(100);
   account.TransferToSavings(300);

   cout << account.GetName() << endl;
   cout << fixed << setprecision(2);
   cout << account.GetChecking() << endl;
   cout << account.GetSavings() << endl;

   return 0;
}
