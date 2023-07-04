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