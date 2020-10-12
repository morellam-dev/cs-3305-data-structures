/**
 * @file main.cpp
 * @author M Morella
 * @brief Test program for the Account class
 */
#include <cstdio>
#include <iostream>

#include "Account.h"
/** Prints the name and balance of the given Account
 */
void print_account_statement(Account acct);
/** An example program which demonstrates functionality of the account class.
 */
int main() {
  Account egbert = Account("John Egbert");
  print_account_statement(egbert);
  printf("> John:  Deposit $%.2f [Balance: $%.2f]\n", 9.99,
         egbert.deposit(9.99));
  printf("> John: Withdraw $%.2f [Result: $%.2f]\n", 6.12,
         egbert.withdraw(6.12));
  printf("> John: Withdraw $%.2f [Result: $%.2f]\n", 4.13,
         egbert.withdraw(4.13));
  print_account_statement(egbert);

  printf("> John:  Change name to June\n");
  egbert.setAccountHolder("June Egbert");
  printf("> June:  Deposit $%.2f [Balance: $%.2f]\n", 0.26,
         egbert.deposit(0.26));
  print_account_statement(egbert);
}
void print_account_statement(Account acct) {
  printf("\n=== NAME: %s - BALANCE: $%.2f ===\n\n",
         acct.getAccountHolder().c_str(), acct.getBalance());
}