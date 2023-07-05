#include "main.h"

int main(){
    DataOperator dataOperator;
    dataOperator.loadUsers("base.csv");
    dataOperator.currencyPriceGen("currency.csv");

    std::string option;
    bool validOption = false;

    std::cout << " |  Your exchange center  |" << std::endl;
    std::cout << " Choose option ( type '1' or '2' ) " << std::endl;
    std::cout << " | 1) Login  | 2) Register |" << std::endl;

    while (!validOption) {
        std::cin >> option;

        if (option == "1") {
            auto user = dataOperator.loginSystem();

            if(user.getFirstName() == "admin"){
                dataOperator.adminSystem(user);
            }else{
                dataOperator.userSystem(user);
            }

            validOption = true;

        } else if (option == "2") {
            dataOperator.registerSystem();
            break;

        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    dataOperator.saveToFile();
}
