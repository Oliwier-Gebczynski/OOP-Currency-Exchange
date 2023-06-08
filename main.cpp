/*
 * TODO:
 * Warto jeszcze dodać rysunek klas z powiązaniami... Proszę przemyśleć pomysł,
 *  - czy nie dało by się utworzyć klasy waluta (abstrakcyjna) i z niej wyprowadzić konkretne waluty zapisane w tablicy,
 *  - Zmiana wartosci waluty co wlaczenie programu - done
 *      - generowanie tych wartosci w jakims danym zakresie - done
 *  - znalezc jakiego przyklady UI
 *
 *  - PANEL USER:
 *      - main panel
 *          - wplacanie srodkow  - 1/2 done
 *
 *          - wyplacanie srodkow
 *
 *          - zmiana hasla
 *
 *          - usuniecie konta
 *
 *          - podglad na aktualne ceny walut
 *
 *          - wyloguj
 *
 *  - PANEL ADMIN:
 *      - main panel
 *          - zazadzanie userem
 *              - usuwanie
 *              - zmiana salda
 *              - dodawanie nowych kont
 *
 * DONE:
 *   - Drobna uwaga: jak ID nadawane jest na stale to może z tego zrobić const? DONE
 * */

#include "main.h"

int main(){
    DataOperator dataOperator;
    dataOperator.loadUsers("base.csv");
//    dataOperator.addUser("Ola", "Makota", "makota@gmail.com", "haslomaslo", 1987);
//    dataOperator.addUser("Marcin", "Szostak", "kukon@gmail.com", "maslo", 1387);
//    dataOperator.addUser("Krzys", "Rower", "roweromania@gmail.com", "haslo", 1122);
//    dataOperator.displayUsers();
//    dataOperator.loginSystem();
//    dataOperator.registerSystem();
    dataOperator.currencyPriceGen("currency.csv");

//    auto test = dataOperator.getCurrencies();
//
//    for(Currency currency: test){
//        std::cout << currency.getCode() << " [ " << currency.getName() << " ] : " << currency.getExchangeRate() << std::endl;
//    }

    User& userRef = dataOperator.getUser(3);


    userRef.getWallet().addCurrency("USD", 420);


    std::cout << "Nowa wartość USD dla użytkownika o ID " << 3 << ": " << userRef.getWallet().getUSD() << std::endl;



    dataOperator.getUsers();
    dataOperator.saveToFile();



}
