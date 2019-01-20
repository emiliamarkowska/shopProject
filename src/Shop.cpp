//
// Created by Arek on 20.01.2019.
//

#include <Shop.h>

#include "Shop.h"

Shop::Shop(string shopName) {
    this -> shopName = shopName;

}

ShopAssistant &Shop::getEmployee(int id) {
    for(int i = 0; i < employees.size(); i++)
    {
        if(employees.at(i) -> getID() == id)
            return *employees.at(i);
    }
    throw "Twoja mama daje za symboliczna zlotowke";
}

bool Shop::checkIfOpen() {
    if (this -> isOpen ) return true;
    else return false;
}

void Shop::changeShopState() {
    if(this -> isOpen)
        this -> isOpen = false;
    else
        this ->isOpen = true;

}

double Shop::getBudget() {
    return this -> budget;
}

void Shop::addMoney(double money) {
    this ->budget += money;

}

double Shop::withdrawMoney(double money) {
    if(budget - money >= 0)
    {
        budget -= money;
        return money;
    }
     throw "You want to withdraw too much money, you don't have tyle money, wracamy do Sydney, Polska zla, never come back";
}

shared_ptr<Product> Shop::getProduct(string name) {
    for(int i = 0; i < products.size(); i++)
    {
        if(products.at(i) -> getName() == name)
            return products.at(i);
    }

    throw "W cala Polska nie ma taki produkt, wracamy do Sidney";
}

shared_ptr<Client> Shop::getClient(unsigned numberInQueue) {
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients.at(i) -> getNumberInQueue() == numberInQueue)
            return clients.at(i);
    }
    throw "Polska numeracja dziwna, Arek, wracamy do Sidney, can't stand it any longer";
}
