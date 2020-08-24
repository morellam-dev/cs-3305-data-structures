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
