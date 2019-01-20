//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include<memory>
#include <vector>
#include <Product.h>
#include <ShopAssistant.h>

class Client {
private:
    double money;
    vector<shared_ptr<Product>> shoppingCart;
    double currentCost();

public:
    Client(double money);
    void addToCart(shared_ptr<Product> product);
    void removeFromCart(shared_ptr<Product> product);
    void buyProducts(ShopAssistant sa);
    double getMoney();
    void addMoney(double amount);
    void pay(double amount);


};


#endif //PROJECT_CLIENT_H
