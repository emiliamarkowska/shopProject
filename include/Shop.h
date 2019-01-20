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
#include <thread>
#include <chrono>



class Shop {
private:
    string shopName;
    bool isOpen;
    double budget;
    vector<shared_ptr<Product>> products;
    shared_ptr<ShopAssistant> shopAssistant;
    vector<shared_ptr<Client>> queue;
    std::thread clientsTh;
    std::thread staffTh;

public:
    Shop(string shopName);
    bool checkIfOpen();
    void changeShopState();
    double getBudget();
    void addMoney(double money);
    double withdrawMoney(double money);
    shared_ptr<Product> getProduct(string name);
    shared_ptr<Client> getClient(unsigned numberInQueue);
    void serveCustomers();
    void simulateClients();

};


#endif //PROJECT_SHOP_H
