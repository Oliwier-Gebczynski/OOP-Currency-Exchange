
#include "user.h"

User::User() {

}

std::string User::getFullName() {
    return std::string();
}

std::string User::getEmail() {
    return std::string();
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

std::string User::setPassword() {
    return std::string();
}

std::string User::changePassword() {
    return std::string();
}

std::string User::changeEmail() {
    return std::string();
}

void User::deleteAccount() {

}

int User::setPIN() {
    return 0;
}

void User::displayCurrencyStatus() {

}

void User::addCurrency(std::string currencyCode, double amount) {

}

void User::subtractCurrency(std::string currencyCode, double amount) {

}

void User::exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount) {

}

Wallet &User::exchangeCurrency(Currency currency) {
    return <#initializer#>;
}

