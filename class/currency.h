#include "main.h"

/**
 * @class Currency
 * @brief A class representing a currency with its code, name, and exchange rate.
 */
class Currency {
private:
    std::string code; ///< Currency code.
    std::string name; ///< Currency name.
    double exchangeRate; ///< Currency exchange rate.

public:
    /**
     * @brief Default constructor for the Currency class.
     */
    Currency();

    /**
     * @brief Constructor for the Currency class with parameters.
     * @param code The currency code.
     * @param name The currency name.
     * @param exchangeRate The currency exchange rate.
     */
    Currency(std::string code, std::string name, double exchangeRate)
            : code(std::move(code)), name(std::move(name)), exchangeRate(exchangeRate) {}

    // Accessor functions

    /**
     * @brief Retrieves the currency code.
     * @return The currency code.
     */
    std::string getCode();

    /**
     * @brief Retrieves the currency name.
     * @return The currency name.
     */
    std::string getName();

    /**
     * @brief Retrieves the currency exchange rate.
     * @return The currency exchange rate.
     */
    double getExchangeRate();
};