#include "main.h"

void DataOperator::loadUsers(std::string fileName) {

}

void DataOperator::addUser(std::string firstName, std::string lastName, std::string email, std::string password, int PIN) {
    Wallet wallet;
    User user(std::move(firstName), std::move(lastName), std::move(email), std::move(password), PIN, wallet);
    users.push_back(user);
}

void DataOperator::removeUser(int id) {

}

void DataOperator::displayUsers() {
    for(User user: users){
        std::cout << "ID: " <<user.getID() << " Full name: " << user.getFullName() << " Email: " << user.getEmail() << std::endl;
    }
}

std::vector<User> DataOperator::getUsers() {
    return users;
}
