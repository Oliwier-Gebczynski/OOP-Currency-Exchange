#include "main.h"

class Currency {
private:
    std::string code;
    std::string name;
    double exchangeRate;

public:
    Currency();
    Currency(std::string code, std::string name, double exchangeRate)
            : code(std::move(code)), name(std::move(name)), exchangeRate(exchangeRate) {}

    // Accessor functions
    std::string getCode();
    std::string getName();
    double getExchangeRate();
};

//const Currency USD("USD", "US Dollar", 0.26);
//const Currency EUR("EUR", "Euro", 0.22);
//const Currency JPY("JPY", "Japanese Yen", 29.09);
//const Currency GBP("GBP", "British Pound", 0.19);
//const Currency AUD("AUD", "Australian Dollar", 0.33);
//const Currency CHF("CHF", "Swiss Franc", 0.23);
//const Currency PLN("PLN", "Polish Zloty", 1.0);