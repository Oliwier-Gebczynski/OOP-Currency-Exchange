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
    std::cout << "User added!";
}

void DataOperator::removeUser(int id) {

}

void DataOperator::displayUsers() {
    for(User user: users){
        std::cout << "ID: " <<user.getID() << " Full name: " << user.getFullName() << " Email: " << user.getEmail() << std::endl;
    }
}

std::vector<User>& DataOperator::getUsers() {
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

void DataOperator::loginSystem() {
    std::string email, password;

    bool validData = false;
    while(!validData){
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << std::endl;

        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;

        for (User user: users){
            if((user.getPassword() == password)&&(user.getEmail())==email){
                std::cout << "Succesfull login! Hi " << user.getFullName() << std::endl;
                validData = true;
            }
        }

        if(!validData){
            std::cout << "Invalid email or password. Please try again." << std::endl;
        }

    }



}

void DataOperator::registerSystem() {
    std::cout << "----------- REGISTER ----------" << std::endl;

    std::string firstName, lastName, email, password, PIN;

    //name
    std::cout << "First name: ";
    std::cin >> firstName;
    std::cout << std::endl;

    //last name
    std::cout << "lastName: ";
    std::cin >> lastName;
    std::cout << std::endl;

    //email
    bool validEmail = false;
    while (!validEmail) {
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << std::endl;

        size_t atPos = email.find('@');
        size_t dotPos = email.rfind('.');
        validEmail = (atPos != std::string::npos && dotPos != std::string::npos && dotPos > atPos + 1);
        if (!validEmail) {
            std::cout << "Invalid email address. Please enter a valid email." << std::endl;
        }
    }

    //password
    bool validPassword = false;
    while (!validPassword) {
        std::cout << "Password (must contain at least one special character): ";
        std::cin >> password;
        std::cout << std::endl;

        std::regex specialCharRegex("[!@#$%^&*()]");
        validPassword = std::regex_search(password, specialCharRegex);
        if (!validPassword) {
            std::cout << "Password must contain at least one special character. Please enter a valid password." << std::endl;
        }
    }

    //PIN
    bool validPIN = false;
    while (!validPIN) {
        std::cout << "PIN (must be exactly 4 digits): ";
        std::cin >> PIN;
        std::cout << std::endl;

        if (PIN.length() == 4 && std::all_of(PIN.begin(), PIN.end(), ::isdigit)) {
            validPIN = true;
        }
        else {
            std::cout << "PIN must be exactly 4 digits. Please enter a valid PIN." << std::endl;
        }
    }

    addUser(firstName,lastName,email,password,stoi(PIN));
}

void DataOperator::currencyPriceGen(const std::string& fileName) {

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Failed to open input file." << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string field;

        std::getline(ss, field, ','); // ID
        std::string code = field;

        std::getline(ss, field, ','); // Name
        std::string name = field;

        std::getline(ss, field, ','); // Lower bound
        double lower_bound = stod(field);

        std::getline(ss, field, ','); // Upper bound
        double upper_bound = stod(field);

        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);
        double random_double = distribution(generator);
        random_double = std::floor(random_double * 10000) / 10000;

        Currency currency(code, name, random_double);

        currencies.push_back(currency);
    }
}

DataOperator::DataOperator() {

}

std::vector<Currency> DataOperator::getCurrencies() {
    return currencies;
}

User DataOperator::getUser(int id) {
    for(User user: users){
        if (id == user.getID()){
            return user;
        }
        std::cout << "User doesnt exist!";
    }
}

