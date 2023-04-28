#include "main.h"

class Admin {
private:
    std::string const password;
public:
    Admin() : password("czytwysweja") {}

    void addUser(User user);
    void deleteUser(int ID);
    void modifyUserFirstName(int ID, std::string firstName);
    void modifyUserLastName(int ID, std::string lastName);
    void modifyUserEmail(int ID, std::string email);
    void modifyUserPassword(int ID, std::string password);
    void modifyUserPIN(int ID, int PIN);
};
