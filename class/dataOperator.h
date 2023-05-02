#include "main.h"

class DataOperator {
private:
    std::vector<User> users;

public:
    DataOperator() {}


    void loadUsers(const std::string& fileName);
    void addUser(std::string firstName, std::string lastName, std::string email, std::string password, int PIN);
    void removeUser(int id);
    void displayUsers();
    void saveToFile();
    void loginSystem();
    void registerSystem();

    std::vector<User> getUsers();
};


