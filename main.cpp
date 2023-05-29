/*
 * TODO:
 * Warto jeszcze dodać rysunek klas z powiązaniami... Proszę przemyśleć pomysł,
 *  - czy nie dało by się utworzyć klasy waluta (abstrakcyjna) i z niej wyprowadzić konkretne waluty zapisane w tablicy,
 *  - Zmiana wartosci waluty co wlaczenie programu
 *      - generowanie tych wartosci w jakims danym zakresie
 *  - znalezc jakiego przyklady UI
 *
 *  - PANEL USER:
 *      - main panel
 *          - wplacanie srodkow
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
    dataOperator.displayUsers();
    dataOperator.loginSystem();
//    dataOperator.registerSystem();

    dataOperator.getUsers();
    dataOperator.saveToFile();
}
