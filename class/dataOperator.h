#include "main.h"

/**
 * @class DataOperator
 * @brief A class responsible for managing user data and currency operations.
 */
class DataOperator {
private:
    std::vector<User> users; ///< Vector containing user objects.
    std::vector<Currency> currencies; ///< Vector containing currency objects.
    std::default_random_engine re; ///< Random engine for generating random values.

public:
    /**
     * @brief Default constructor for the DataOperator class.
     */
    DataOperator();

    /**
     * @brief Loads user data from a file.
     * @param fileName The name of the file to load.
     */
    void loadUsers(const std::string& fileName);

    /**
     * @brief Adds a new user to the system.
     * @param firstName The user's first name.
     * @param lastName The user's last name.
     * @param email The user's email address.
     * @param password The user's password.
     * @param PIN The user's PIN number.
     */
    void addUser(std::string firstName, std::string lastName, std::string email, std::string password, int PIN);

    /**
     * @brief Removes a user from the system.
     * @param id The ID of the user to remove.
     */
    void removeUser(int id);

    /**
     * @brief Displays all users in the system.
     */
    void displayUsers();

    /**
     * @brief Saves user data to a file.
     */
    void saveToFile();

    /**
     * @brief Allows a user to log in to the system.
     * @return The logged-in user object.
     */
    User loginSystem();

    /**
     * @brief Registers a new user in the system.
     */
    void registerSystem();

    /**
     * @brief Generates currency prices and saves them to a file.
     * @param fileName The name of the file to save.
     */
    void currencyPriceGen(const std::string& fileName);

    /**
     * @brief Adds a specific amount of a currency to a user's wallet.
     * @param id The ID of the user.
     * @param code The currency code.
     * @param amount The amount to add.
     */
    void addCurrency(int id, const std::string& code, double amount);

    /**
     * @brief Subtracts a specific amount of a currency from a user's wallet.
     * @param id The ID of the user.
     * @param code The currency code.
     * @param amount The amount to subtract.
     */
    void subtractCurrency(int id, const std::string& code, double amount);

    /**
     * @brief Exchanges a certain amount of currency from one type to another.
     * @param code1 The currency code to exchange from.
     * @param code2 The currency code to exchange to.
     * @param amount The amount to exchange.
     * @return A vector containing the exchanged amounts.
     */
    std::vector<double> exchangeCurrency(const std::string& code1, const std::string& code2, double amount);

    /**
     * @brief Exchanges a certain amount of currency from one type to another within a user's wallet.
     * @param id The ID of the user.
     * @param code1 The currency code to exchange from.
     * @param code2 The currency code to exchange to.
     * @param amount The amount to exchange.
     */
    void exchangeUserCurrency(int id, const std::string& code1, const std::string& code2, double amount);

    /**
     * @brief Changes the password of a user.
     * @param id The ID of the user.
     * @param pass The new password.
     */
    void changePassword(int id, std::string pass);

    /**
     * @brief Deletes a user's account.
     * @param id The ID of the user.
     */
    void deleteAccount(int id);

    /**
     * @brief Displays the current costs of currencies.
     */
    void currentCurrencyCost();

    /**
     * @brief Starts the user system for a specific user.
     * @param user The user object.
     */
    void userSystem(User user);

    /**
     * @brief Starts the admin system for a specific user.
     * @param user The user object with admin privileges.
     */
    void adminSystem(User user);

    /**
     * @brief Retrieves the vector of currencies.
     * @return The vector of currencies.
     */
    std::vector<Currency> getCurrencies();

    /**
     * @brief Retrieves a specific user by ID.
     * @param id The ID of the user.
     * @return The user object.
     */
    User getUser(int id);

    /**
     * @brief Retrieves the vector of users.
     * @return The vector of users.
     */
    std::vector<User>& getUsers();
};


