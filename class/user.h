#include "main.h"

/**
 * @class User
 * @brief A class representing a user with personal information and a wallet.
 */
class User {
private:
    static int id_counter; ///< Static counter for assigning unique user IDs.
    int id; ///< User ID.
    std::string firstName; ///< User's first name.
    std::string lastName; ///< User's last name.
    std::string email; ///< User's email address.
    std::string password; ///< User's password.
    int PIN; ///< User's PIN number.
    Wallet wallet; ///< User's wallet object.

public:
    /**
     * @brief Default constructor for the User class.
     */
    User();

    /**
     * @brief Constructor for the User class with parameters.
     * @param firstName The user's first name.
     * @param lastName The user's last name.
     * @param email The user's email address.
     * @param password The user's password.
     * @param PIN The user's PIN number.
     * @param wallet The user's wallet object.
     */
    User(std::string firstName, std::string lastName, std::string email, std::string password, int PIN, Wallet wallet);

    // Getters
    /**
     * @brief Retrieves the user's full name.
     * @return The user's full name.
     */
    std::string getFullName();

    /**
     * @brief Retrieves the user's email address.
     * @return The user's email address.
     */
    std::string getEmail();

    /**
     * @brief Retrieves the user's ID.
     * @return The user's ID.
     */
    int getID() const;

    /**
     * @brief Retrieves the user's first name.
     * @return The user's first name.
     */
    std::string getFirstName();

    /**
     * @brief Retrieves the user's last name.
     * @return The user's last name.
     */
    std::string getLastName();

    /**
     * @brief Retrieves the user's password.
     * @return The user's password.
     */
    std::string getPassword();

    /**
     * @brief Retrieves the user's PIN number.
     * @return The user's PIN number.
     */
    int getPIN();

    /**
     * @brief Retrieves the user's wallet object.
     * @return The user's wallet object.
     */
    Wallet getWallet();

    // Setters
    /**
     * @brief Sets the user's first name.
     * @return The user's first name.
     */
    std::string setFirstName();

    /**
     * @brief Sets the user's last name.
     * @return The user's last name.
     */
    std::string setLastName();

    /**
     * @brief Sets the user's email address.
     * @return The user's email address.
     */
    std::string setEmail();

    /**
     * @brief Sets the user's password.
     * @param pass The new password.
     */
    void setPassword(std::string& pass);

    /**
     * @brief Sets the user's PIN number.
     * @return The user's PIN number.
     */
    int setPIN();

    // User Wallet
    /**
     * @brief Adds a certain amount of a specific currency to the user's wallet.
     * @param currencyCode The currency code.
     * @param amount The amount to be added.
     */
    void addCurrency(std::string currencyCode, double amount);

    /**
     * @brief Subtracts a certain amount of a specific currency from the user's wallet.
     * @param currencyCode The currency code.
     * @param amount The amount to be subtracted.
     */
    void subtractCurrency(std::string currencyCode, double amount);

    /**
     * @brief Exchanges a certain amount of currency from one type to another within the user's wallet.
     * @param fromCurrencyCode The currency code to exchange from.
     * @param toCurrencyCode The currency code to exchange to.
     * @param amount The amount to be exchanged.
     */
    void exchangeCurrency(std::string fromCurrencyCode, std::string toCurrencyCode, double amount);

    // Currency
    /**
     * @brief Displays the status of the currencies in the user's wallet.
     */
    void displayCurrencyStatus();

    // Settings
    /**
     * @brief Changes the user's password.
     * @return The new password.
     */
    std::string changePassword();

    /**
     * @brief Changes the user's email address.
     * @return The new email address.
     */
    std::string changeEmail();

    /**
     * @brief Destructor for the User class.
     */
    ~User();
};