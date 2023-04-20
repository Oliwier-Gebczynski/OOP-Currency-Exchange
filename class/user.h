#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "currency.h"
#include "wallet.h"

class User {
private:
    int ID;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    int PIN;
    Wallet wallet;

public:
    User();
    User(std::string firstName, std::string lastName, std::string email, std::string password, int PIN, Wallet wallet)
            : firstName(std::move(firstName)), lastName(std::move(lastName)), email(std::move(email)), password(std::move(password)) {}

    // get / set
    std::string getFullName();
    std::string getEmail();

    std::string setFirstName();
    std::string setLastName();
    std::string setEmail();
    std::string setPassword();
    int setPIN();

    // user wallet
    void addCurrency(std::string currencyCode, double amount);
    void subtractCurrency(std::string currencyCode, double amount);
    void exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount);


    //currency
    void displayCurrencyStatus();

    //settings
    std::string changePassword();
    std::string changeEmail();
    void deleteAccount();
};
