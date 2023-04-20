#include <fstream>
#include <vector>
#include "User.h"

class DataOperator {
private:
    std::vector<User> users;

public:
    DataOperator() {}

    void loadUsers(std::string fileName);
    void addUser(User user);
    void removeUser(int id);
    void displayUsers();

    std::vector<User> getUsers();
};
