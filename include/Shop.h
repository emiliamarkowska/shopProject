//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_SHOP_H
#define PROJECT_SHOP_H

#include <Product.h>
#include <ShopAssistant.h>
#include "Client.h"
#include <memory>
#include <vector>

class Shop {
private:
    string shopName;
    bool isOpen;
    double budget;
    vector<shared_ptr<Product>> products;
    vector<shared_ptr<ShopAssistant>> employees;
    vector<shared_ptr<Client>> clients;

public:
    Shop(string shopName);
    ShopAssistant& getEmployee(int id);
    bool checkIfOpen();
    void changeShopState();
    double getBudget();
    void addMoney(double money);
    double withdrawMoney(double money);
    shared_ptr<Product> getProduct(string name);
    shared_ptr<Client> getClient(unsigned numberInQueue);

};


#endif //PROJECT_SHOP_H
