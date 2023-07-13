#include "main.h"

/**
 * @class Wallet
 * @brief A class representing a wallet that holds multiple currencies.
 */
class Wallet {
private:
    double USD; ///< Amount of USD in the wallet.
    double EUR; ///< Amount of EUR in the wallet.
    double JPY; ///< Amount of JPY in the wallet.
    double GBP; ///< Amount of GBP in the wallet.
    double AUD; ///< Amount of AUD in the wallet.
    double CHF; ///< Amount of CHF in the wallet.
    double PLN; ///< Amount of PLN in the wallet.

public:
    /**
     * @brief Default constructor for the Wallet class.
     *        Initializes all currency amounts to zero.
     */
    Wallet() : USD(0), EUR(0), JPY(0), GBP(0), AUD(0), CHF(0), PLN(0) {}

    /**
     * @brief Getter for the amount of USD in the wallet.
     * @return The amount of USD.
     */
    double getUSD() const;

    /**
     * @brief Getter for the amount of EUR in the wallet.
     * @return The amount of EUR.
     */
    double getEUR() const;

    /**
     * @brief Getter for the amount of JPY in the wallet.
     * @return The amount of JPY.
     */
    double getJPY() const;

    /**
     * @brief Getter for the amount of GBP in the wallet.
     * @return The amount of GBP.
     */
    double getGBP() const;

    /**
     * @brief Getter for the amount of AUD in the wallet.
     * @return The amount of AUD.
     */
    double getAUD() const;

    /**
     * @brief Getter for the amount of CHF in the wallet.
     * @return The amount of CHF.
     */
    double getCHF() const;

    /**
     * @brief Getter for the amount of PLN in the wallet.
     * @return The amount of PLN.
     */
    double getPLN() const;

    /**
     * @brief Retrieves the value of a specific currency.
     * @param code The currency code.
     * @return The value of the currency.
     */
    double getCurrencyValue(std::string code);

    /**
     * @brief Displays the wallet with the amounts of each currency.
     */
    void displayWallet();

    /**
     * @brief Adds a certain amount of a specific currency to the wallet.
     * @param currencyCode The currency code.
     * @param amount The amount to be added.
     */
    void addCurrency(std::string currencyCode, double amount);

    /**
     * @brief Subtracts a certain amount of a specific currency from the wallet.
     * @param currencyCode The currency code.
     * @param amount The amount to be subtracted.
     */
    void subtractCurrency(std::string currencyCode, double amount);

    /**
     * @brief Exchanges a certain amount of currency from one type to another.
     * @param fromCurrencyCode The currency code to exchange from.
     * @param toCurrencyCode The currency code to exchange to.
     * @param amount The amount to be exchanged.
     */
    void exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount);
};

