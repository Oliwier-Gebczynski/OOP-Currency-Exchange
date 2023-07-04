#include "main.h"

User::User() {

}

std::string User::getFullName() {
    std::string fullName = firstName;
    fullName.append(" ");
    fullName.append(lastName);
    return fullName;
}

std::string User::getEmail() {
    return email;
}

int User::getID() const{
    return id;
}

std::string User::setFirstName() {
    return std::string();
}

std::string User::setLastName() {
    return std::string();
}

std::string User::setEmail() {
    return std::string();
}

void User::setPassword(std::string& pass) {
    password = pass;
}

std::string User::changePassword() {
    return std::string();
}

std::string User::changeEmail() {
    return std::string();
}

int User::setPIN() {
    return 0;
}

void User::displayCurrencyStatus() {

}

void User::addCurrency(std::string currencyCode, double amount) {
    wallet.addCurrency(std::move(currencyCode), amount);
}

void User::subtractCurrency(std::string currencyCode, double amount) {
    wallet.subtractCurrency(std::move(currencyCode), amount);
}

void User::exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount) {

}

int User::id_counter = 0;

std::string User::getFirstName() {
    return firstName;
}

std::string User::getLastName() {
    return lastName;
}

std::string User::getPassword() {
    return password;
}

int User::getPIN() {
    return PIN;
}

Wallet User::getWallet() {
    return wallet;
}


