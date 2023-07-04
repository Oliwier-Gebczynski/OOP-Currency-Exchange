#include "main.h"

class DataOperator {
private:
    std::vector<User> users;
    std::vector<Currency> currencies;
    std::default_random_engine re;

public:
    DataOperator();

    void loadUsers(const std::string& fileName);
    void addUser(std::string firstName, std::string lastName, std::string email, std::string password, int PIN);
    void removeUser(int id);
    void displayUsers();
    void saveToFile();
    void loginSystem();
    void registerSystem();
    void currencyPriceGen(const std::string& fileName);
    void addCurrency(int id, const std::string& code, double amount);
    void subtractCurrency(int id, const std::string& code, double amount);
    void exchangeCurrency(const std::string& code1, const std::string& code2, double amount);
    void changePassword(int id, std::string pass);
    void deleteAccount(int id);
    void currentCurrencyCost();

    std::vector<Currency> getCurrencies();
    User getUser(int id);
    std::vector<User>& getUsers();
};


