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