#include "main.h"

class User {
private:
    static int id_counter;
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    int PIN;
    Wallet wallet;

public:
    User();
    User(std::string firstName, std::string lastName, std::string email, std::string password, int PIN, Wallet wallet)
            : id(++id_counter), firstName(std::move(firstName)), lastName(std::move(lastName)), email(std::move(email)), password(std::move(password)), PIN(PIN), wallet(wallet) {
        id_counter += 1;
    }

    // get / set
    std::string getFullName();
    std::string getEmail();
    int getID() const;
    std::string getFirstName();
    std::string getLastName();
    std::string getPassword();
    int getPIN();
    Wallet getWallet();

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
