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
 *          - wplacanie srodkow  - done
 *
 *          - wyplacanie srodkow - done
 *
 *          - zmiana waluty z jedna na druga - done
 *
 *          - wymiana miedzy walutami - done
 *
 *          - zmiana hasla - done
 *
 *          - usuniecie konta - done
 *
 *          - podglad na aktualne ceny walut - done
 *
 *          - wyloguj -
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
    dataOperator.currencyPriceGen("currency.csv");

    dataOperator.saveToFile();
}
