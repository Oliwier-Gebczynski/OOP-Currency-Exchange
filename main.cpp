#include "main.h"

int main(){
    DataOperator dataOperator;
    dataOperator.loadUsers("base.csv");
//    dataOperator.addUser("Ola", "Makota", "makota@gmail.com", "haslomaslo", 1987);
//    dataOperator.addUser("Marcin", "Szostak", "kukon@gmail.com", "maslo", 1387);
//    dataOperator.addUser("Krzys", "Rower", "roweromania@gmail.com", "haslo", 1122);
    dataOperator.displayUsers();

    dataOperator.registerSystem();

    dataOperator.getUsers();
    dataOperator.saveToFile();
}
