#include "main.h"

void Wallet::displayWallet() {

}

void Wallet::addCurrency(std::string currencyCode, double amount) {
    std::transform(currencyCode.begin(), currencyCode.end(), currencyCode.begin(), ::tolower);

    switch (currencyCode[0]) {
        case 'u':
            USD += amount;
            break;
        case 'e':
            EUR += amount;
            break;
        case 'j':
            JPY += amount;
            break;
        case 'g':
            GBP += amount;
            break;
        case 'a':
            AUD += amount;
            break;
        case 'c':
            CHF += amount;
            break;
        case 'p':
            PLN += amount;
            break;
        default:
            std::cout << "Nieznany skrót waluty: " << currencyCode << std::endl;
            break;
    }
}

void Wallet::subtractCurrency(std::string currencyCode, double amount) {
    std::transform(currencyCode.begin(), currencyCode.end(), currencyCode.begin(), ::tolower);

    switch (currencyCode[0]) {
        case 'u':
            USD -= amount;
            break;
        case 'e':
            EUR -= amount;
            break;
        case 'j':
            JPY -= amount;
            break;
        case 'g':
            GBP -= amount;
            break;
        case 'a':
            AUD -= amount;
            break;
        case 'c':
            CHF -= amount;
            break;
        case 'p':
            PLN -= amount;
            break;
        default:
            std::cout << "Nieznany skrót waluty: " << currencyCode << std::endl;
            break;
    }
}

void Wallet::exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount) {

}

double Wallet::getUSD() const{ return USD; }
double Wallet::getEUR() const{ return EUR; }
double Wallet::getJPY() const{ return JPY; }
double Wallet::getGBP() const{ return GBP; }
double Wallet::getAUD() const{ return AUD; }
double Wallet::getCHF() const{ return CHF; }
double Wallet::getPLN() const{ return PLN; }

double Wallet::getCurrencyValue(std::string code) {
    double currencyValue = 0.0;

    switch (code[0]) {
        case 'U':
            currencyValue = USD;
            break;
        case 'E':
            currencyValue = EUR;
            break;
        case 'J':
            currencyValue = JPY;
            break;
        case 'G':
            currencyValue = GBP;
            break;
        case 'A':
            currencyValue = AUD;
            break;
        case 'C':
            currencyValue = CHF;
            break;
        case 'P':
            currencyValue = PLN;
            break;
        default:
            std::cout << "ERROR: " << code << std::endl;
            break;
    }

    return currencyValue;
}
