# CS 3305 Data Structures

Max Morella

## Homework Assignment 2

### 1. Time Analysis

**a.** $O(n)$

**b.** $O(n^2)$

**c.** $O(n^3)$

**d.** $O(n^2)$

**e.** $O(n^4)$

### 2. Programming

#### Account.h

```cpp
/**
 * @file Account.h
 * @brief An example OOP class which models a bank account.
 * @author M Morella
 */
#include <string>
/** @class
 * @brief Simulates a bank account.
 *
 * Stores the name of the account holder and the account's balance.
 * Provides methods for withdrawing and depositing money,
 * and changing the account holder's name.
 * The account balance cannot drop below 0.
 */
class Account
{
public:
    Account(std::string name);
    std::string getAccountHolder() const;
    double getBalance() const;
    void setAccountHolder(std::string name);
    double deposit(double amount);
    double withdraw(double amount);
private:
    std::string account_holder; // name of the account holder
    double balance; // the account balance
};
```

#### Account.cpp

```cpp
/**
 * @file Account.cpp
 * @brief Implementation of Account.h
 * @author M Morella
 */
#include "Account.h"
#include <cassert>

/** Creates a new Account with a balance of 0.00
 * @param name The name of the account holder.
 */
Account::Account(std::string name)
{
    assert (name.length() > 0);
    setAccountHolder(name);
    balance = 0;
}
/** @return The name of the account holder.
 */
std::string Account::getAccountHolder() const 
{
    return account_holder;
}
/** @return The current account balance.
 */
double Account::getBalance() const
{
    return balance;
}
/** Sets the name of the account holder.
 * @param name The name of the account holder.
 */
void Account::setAccountHolder(std::string name)
{
    account_holder = name;
}
/** Deposit money into the account.
 * @param amount The amount to deposit (must be > 0.0)
 * @return The new balance of the account.
 */
double Account::deposit(double amount)
{
    assert (amount > 0);
    balance = getBalance() + amount;
    return getBalance();
}
/** Attempt to withdraw money from the account.
 * Withdrawal is only successful if there are sufficient funds.
 * @param amount The amount to withdraw (must be > 0.0)
 * @return The amount which was withdrawn. If insufficient funds, returns 0.0
 */
double Account::withdraw(double amount)
{
    assert (amount > 0);
    if (getBalance() - amount >= 0) {
        balance = getBalance() - amount;
        return amount;
    } else {
        return 0;
    }
}
```

### main.cpp

```cpp
/**
 * @file main.cpp
 * @author M Morella
 * @brief Test program for the Account class
 */
#include "Account.h"
#include <iostream>
#include <cstdio>
/** Prints the name and balance of the given Account
 */
void print_account_statement(Account acct);
/** An example program which demonstrates functionality of the account class.
 */
int main()
{
    Account egbert = Account("John Egbert");
    print_account_statement(egbert);
    printf("> John:  Deposit $%.2f [Balance: $%.2f]\n", 9.99, egbert.deposit(9.99));
    printf("> John: Withdraw $%.2f [Result: $%.2f]\n", 6.12, egbert.withdraw(6.12));
    printf("> John: Withdraw $%.2f [Result: $%.2f]\n", 4.13, egbert.withdraw(4.13));
    print_account_statement(egbert);

    printf("> John:  Change name to June\n");
    egbert.setAccountHolder("June Egbert");
    printf("> June:  Deposit $%.2f [Balance: $%.2f]\n", 0.26, egbert.deposit(0.26));
    print_account_statement(egbert);
}
void print_account_statement(Account acct)
{
    printf("\n=== NAME: %s - BALANCE: $%.2f ===\n\n", 
        acct.getAccountHolder().c_str(), acct.getBalance());
}
```

#### Result

![Screenshot of program being executed](https://i.imgur.com/lCILfjv.png)
