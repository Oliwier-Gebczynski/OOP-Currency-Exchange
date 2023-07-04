#include "main.h"

class Wallet {
private:
    double USD;
    double EUR;
    double JPY;
    double GBP;
    double AUD;
    double CHF;
    double PLN;

public:
    Wallet() : USD(0), EUR(0), JPY(0), GBP(0), AUD(0), CHF(0), PLN(0) {}

    double getUSD() const;
    double getEUR() const;
    double getJPY() const;
    double getGBP() const;
    double getAUD() const;
    double getCHF() const;
    double getPLN() const;
    double getCurrencyValue(std::string code);

    void displayWallet();
    void addCurrency(std::string currencyCode, double amount);
    void subtractCurrency(std::string currencyCode, double amount);
    void exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount);

};

