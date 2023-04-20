#include "wallet.h"

Currency Wallet::getCurrency() {
    return Currency(__cxx11::basic_string(), __cxx11::basic_string(), 0);
}


void Wallet::displayWallet() {

}

void Wallet::addCurrency(std::string currencyCode, double amount) {

}

void Wallet::subtractCurrency(std::string currencyCode, double amount) {

}

void Wallet::exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount) {

}
