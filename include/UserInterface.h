//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_USERINTERFACE_H
#define PROJECT_USERINTERFACE_H

#include "Shop.h"
#include <iostream>

using namespace std;

class UserInterface {
private:
    shared_ptr<Shop> shop;
public:
    UserInterface();
    void displayClientsInformation();
    void displayProductsInformation();
    void changeShopState();
    void changeSalary();
    void buyProducts();
    void withdrawMoney();
    void checkMoneyState();
    void displayMenu();
    void start();

};


#endif //PROJECT_USERINTERFACE_H
