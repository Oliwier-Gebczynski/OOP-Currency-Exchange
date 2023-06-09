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

User DataOperator::loginSystem() {
    std::string email, password;

    while(true){
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << std::endl;

        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;

        for (User user: users){
            if((user.getPassword() == password)&&(user.getEmail())==email){
                std::cout << "Succesfull login! Hi " << user.getFullName() << std::endl;
                return user;
            }
        }

        std::cout << "Invalid email or password. Please try again." << std::endl;

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
    for(User& user: users){
        if (id == user.getID()){
            return user;
        }
        std::cout << "User doesnt exist!";
    }
}

void DataOperator::addCurrency(int id, const std::string& code, double amount) {
    for (User& user : users) {
        if (user.getID() == id) {
            user.addCurrency(code, amount);
            break;
        }
    }
}

void DataOperator::subtractCurrency(int id, const std::string& code, double amount) {
    for (User& user : users) {
        if (user.getID() == id) {
            user.subtractCurrency(code, amount);
            break;
        }
    }
}

void DataOperator::changePassword(int id, std::string pass) {
    for (User& user : users) {
        if (user.getID() == id) {
            user.setPassword(pass);
            break;
        }
    }
}

void DataOperator::deleteAccount(int id) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getID() == id) {
            users.erase(it);
            break;
        }
    }
}

void DataOperator::currentCurrencyCost() {
    std::cout << " |$| Currency cost |$| " << std::endl;
    for(auto cur: currencies){
        if(cur.getCode() != "PLN"){
            std::cout << " | ";
            exchangeCurrency(cur.getCode(), "PLN", 1);
            std::cout<< " | " << std::endl;
        }
    }
}

std::vector<double> DataOperator::exchangeCurrency(const std::string& code1, const std::string& code2, double amount) {
    Currency first;
    Currency second;

    for (auto cur : currencies) {
        if (cur.getCode() == code1) {
            first = cur;
        } else if (cur.getCode() == code2) {
            second = cur;
        }
    }

    double convertedAmount = amount * (second.getExchangeRate() / first.getExchangeRate());
    std::cout << amount << " " << code1 << " = " << convertedAmount << " " << code2;

    std::vector<double> result;
    result.push_back(amount);
    result.push_back(convertedAmount);

    return result;
}

void DataOperator::exchangeUserCurrency(int id ,const std::string& code1, const std::string& code2, double amount) {

    for(User user: users){
        if (user.getID() == id && user.getWallet().getCurrencyValue(code1) < amount){
            std::cout << "You don't have enough " << code1 << "!" << std::endl;
            return;
        }
    }
    auto amounts = exchangeCurrency(code1, code2, amount);

    addCurrency(id, code2, amounts[1]);
    subtractCurrency(id, code1, amounts[0]);
}

void DataOperator::userSystem(User user) {
    std::string option;

    while(true){
        std::cout << " | 1) Current price | 2) Add money | 3) Exchange money | 4) Subtract money | 5) Change password | 6) Logout | ( type '1' or ... '5' )"  << std::endl;
        std::cin >> option;

        if (option == "1"){
            currentCurrencyCost();
        }else if (option == "2"){
            std::string code;
            double amount;

            std::cout << "Type - code: ";
            std::cin >> code;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            addCurrency(user.getID(), code, amount);
        }else if (option == "3"){
            std::string code1, code2;
            double amount;

            std::cout << "Type - code form: ";
            std::cin >> code1;

            std::cout << "Type - code to: ";
            std::cin >> code2;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            exchangeUserCurrency(user.getID(), code1, code2, amount);
        }else if (option == "4"){
            std::string code;
            double amount;

            std::cout << "Type - code: ";
            std::cin >> code;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            subtractCurrency(user.getID(), code, amount);
        }else if (option == "5"){
            std::string currPass, newPass;
            std::cout << "Type current password: ";
            std::cin >> currPass;

            bool validPass = false;
            while(!validPass){
                if(currPass == user.getPassword()){
                    std::cout << "New password: ";
                    std::cin >> newPass;

                    changePassword(user.getID(), newPass);
                    validPass = true;
                }else{
                    std::cout << "Incorrect password!" << std::endl;
                    std::cout << "Type current password: ";
                    std::cin >> currPass;
                }
            }
        }else if(option == "6"){
            break;
        }
    }

    std::cout << "Logout... ";
}

void DataOperator::adminSystem(User user) {
    std::string option;

    while(true){
        std::cout << " | 1) Add money | 2) Exchange money | 3) Subtract money | 4) Change password | 5) Delete user | 6) Logout | ( type '1' or ... '5' )"  << std::endl;
        std::cin >> option;

        if (option == "1"){
            std::string code;
            double amount;
            int id;

            std::cout << "Type - user id: ";
            std::cin >> id;

            std::cout << "Type - code: ";
            std::cin >> code;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            addCurrency(id, code, amount);
        }else if (option == "2"){
            std::string code1, code2;
            double amount;
            int id;

            std::cout << "Type - user id: ";
            std::cin >> id;

            std::cout << "Type - code form: ";
            std::cin >> code1;

            std::cout << "Type - code to: ";
            std::cin >> code2;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            exchangeUserCurrency(id, code1, code2, amount);
        }else if (option == "3"){
            std::string code;
            double amount;
            int id;

            std::cout << "Type - user id: ";
            std::cin >> id;

            std::cout << "Type - code: ";
            std::cin >> code;

            std::cout << "Type - amount: ";
            std::cin >> amount;

            subtractCurrency(id, code, amount);
        }else if (option == "4") {
            std::string newPass;
            int id;

            std::cout << "Type - user id: ";
            std::cin >> id;

            std::cout << "Type new password: ";
            std::cin >> newPass;

            changePassword(id, newPass);
        }else if (option == "5") {
            int id;

            std::cout << "Type - user id: ";
            std::cin >> id;

            deleteAccount(id);
        }else if(option == "6"){
            break;
        }
    }

    std::cout << "Logout... ";
}

