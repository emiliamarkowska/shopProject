//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_SHOP_H
#define PROJECT_SHOP_H

#include <Product.h>
#include <ShopAssistant.h>
#include "Client.h"
#include "Food.h"
#include "Clothes.h"
#include "Electronics.h"
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include<mutex>



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
    mutex mx;
    Shop(string shopName);
    bool checkIfOpen();
    void changeShopState();
    double getBudget();
    void addMoney(double money);
    double withdrawMoney(double money);
    shared_ptr<Product> getProduct(string name);
    void addProduct(shared_ptr<Product> product);
    shared_ptr<Client> getClient(unsigned numberInQueue);
    void serveCustomers();
    void simulateClients();
    int getQueueSize();
    shared_ptr<Client> getClientFromQueue(int numberInQueue);
    void getInformationAboutProducts();
    shared_ptr<ShopAssistant> getShopAssistant();
    string getShopName();

};


#endif //PROJECT_SHOP_H
