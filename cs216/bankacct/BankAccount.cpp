#include <iostream>
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount(string newName, double chBalance, double sBalance) {
    custName = newName;
    chkBal = chBalance;
    savBal = sBalance;
}

void BankAccount::SetName(string newName) {
    custName = newName;
}
string BankAccount::GetName() {
    return custName;
}
void BankAccount::SetChecking(double balance) {
    if (balance > 0) chkBal = balance;
}
double BankAccount::GetChecking() {
    return chkBal;
}
void BankAccount::SetSavings(double balance) {
    if (balance > 0) savBal = balance;
}
double BankAccount::GetSavings() {
    return savBal;
}
void BankAccount::DepositChecking(double amt) {
    if (amt > 0) chkBal += amt;
}
void BankAccount::DepositSavings(double amt) {
    if (amt > 0) savBal += amt;
}
void BankAccount::WithdrawChecking(double amt) {
    if (amt > 0) chkBal -= amt;
}
void BankAccount::WithdrawSavings(double amt) {
    if (amt > 0) savBal -= amt;
}
void BankAccount::TransferToSavings(double amt) {
    if (amt > 0) {
        chkBal -= amt;
        savBal += amt;
    } 
}