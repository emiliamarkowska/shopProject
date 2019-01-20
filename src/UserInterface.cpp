//
// Created by Arek on 20.01.2019.
//

#include <UserInterface.h>

#include "UserInterface.h"

UserInterface::UserInterface(shared_ptr<Shop> shop) {
    this -> shop = std::make_shared<Shop> ("Elily&Aurora");

}

void UserInterface::displayClientsInformation() {
    cout << "Total amount of clients: " << this -> shop -> getQueueSize() << endl;
    for (int i = 0 ; i < this -> shop -> getQueueSize(); i++)
    {
        cout << "Client " << i+1 << endl;
        cout << this -> shop -> getClientFromQueue(i) ->getInformation() << endl;
    }
}

void UserInterface::displayProductsInformation() {
    this -> shop -> getInformationAboutProducts();

}

void UserInterface::changeShopState() {
    this -> shop ->changeShopState();

}

void UserInterface::changeSalary(int amountToChange) {
    this -> shop -> getShopAssistant() -> setSalary(amountToChange);
}

void UserInterface::buyProducts() {
    cout <<"Good Morning, welcome in BuyProductsToYourShop service, we will do anything to satisfy your current needs, we offer very large choice of goods << endl;
    cout << "Which one of those you would like to buy?" << endl;
    cout << "1. "

}

void UserInterface::withdrawMoney() {

}

void UserInterface::checkMoneyState() {

}
