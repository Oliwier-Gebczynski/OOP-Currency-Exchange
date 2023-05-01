#include "main.h"

void DataOperator::loadUsers(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string field;

        std::getline(ss, field, ','); // ID
        int id = std::stoi(field);

        std::getline(ss, field, ','); // First Name
        std::string firstName = field;

        std::getline(ss, field, ','); // Last Name
        std::string lastName = field;

        std::getline(ss, field, ','); // Email
        std::string email = field;

        std::getline(ss, field, ','); // Password
        std::string password = field;

        std::getline(ss, field, ','); // PIN
        int pin = std::stoi(field);

        std::getline(ss, field, ','); // USD
        double usd = std::stod(field);

        std::getline(ss, field, ','); // EUR
        double eur = std::stod(field);

        std::getline(ss, field, ','); // JPY
        double jpy = std::stod(field);

        std::getline(ss, field, ','); // GBP
        double gbp = std::stod(field);

        std::getline(ss, field, ','); // AUD
        double aud = std::stod(field);

        std::getline(ss, field, ','); // CHF
        double chf = std::stod(field);

        std::getline(ss, field, ','); // PLN
        double pln = std::stod(field);

        Wallet wallet;
        wallet.addCurrency("USD", usd);
        wallet.addCurrency("EUR", eur);
        wallet.addCurrency("JPY", jpy);
        wallet.addCurrency("GBP", gbp);
        wallet.addCurrency("AUD", aud);
        wallet.addCurrency("CHF", chf);
        wallet.addCurrency("PLN", pln);

        User user(firstName, lastName, email, password, pin, wallet);
        users.push_back(user);
    }

    inputFile.close();
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

void DataOperator::saveToFile() {
    std::ofstream file("base.csv");
    for (User user: users){
        file << user.getID() << "," << user.getFirstName() << "," << user.getLastName() << "," << user.getEmail() << "," << user.getPassword() << "," << user.getPIN() << ",";

        file << user.getWallet().getUSD();
        file << "," << user.getWallet().getEUR();
        file << "," << user.getWallet().getJPY();
        file << "," << user.getWallet().getGBP();
        file << "," << user.getWallet().getAUD();
        file << "," << user.getWallet().getCHF();
        file << "," << user.getWallet().getPLN() << std::endl;
    }

    file.close();
}
