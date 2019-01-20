//
// Created by Arek on 20.01.2019.
//

#include <Shop.h>

#include "Shop.h"
#include "iostream"
#include <time.h>

const int SERVING_TIME = 10;

Shop::Shop(string shopName) {
    this -> shopName = shopName;
    this -> shopAssistant = std::make_shared<ShopAssistant> ("John", 1, 2200);
    this -> isOpen = false;
    this -> budget = 10000;

    for (int i = 0; i < 20; i++)
    {
        products.push_back(std::make_shared<Food> (2, "Carrot", 20));
        products.push_back(std::make_shared<Food> (1.5, "Bread", 3));
        products.push_back(std::make_shared<Food> (10, "Chicken", 10));
        products.push_back(std::make_shared<Clothes> (40, "T-Shirt", 36));
        products.push_back(std::make_shared<Clothes> (100, "Shoes", 40));
        products.push_back(std::make_shared<Clothes> (80, "Jeans", 38));
        products.push_back(std::make_shared<Electronics> (800, "Smartphone", 2));
        products.push_back(std::make_shared<Electronics> (4000, "TV", 3));
    }

}

void Shop::getInformationAboutProducts() {
    int carrotCount = 0;
    int breadCount = 0;
    int chickenCount = 0;
    int tshirtCount = 0;
    int shoesCount = 0;
    int jeansCount = 0;
    int smartphoneCount = 0;
    int tvCount = 0;
    if(products.size() == 0)
    {
        cout << "No products in shop" << endl;
        return;
    }
    cout << "Products total: " << products.size() << endl;
    for(int i = 0; i < products.size() ; i++)
    {
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
        if(products.at(i) -> getName() == "Bread")  carrotCount++;
        if(products.at(i) -> getName() == "")  carrotCount++;
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
        if(products.at(i) -> getName() == "Carrot")  carrotCount++;
    }

}


bool Shop::checkIfOpen() {
    if (this -> isOpen ) return true;
    else return false;
}

void Shop::changeShopState() {
    if(this -> isOpen) {
        this->isOpen = false;
        clientsTh.join();
    }
    else {
        this->isOpen = true;
        clientsTh = std::thread(&Shop::simulateClients, this);
    }
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
    for(int i = 0; i < queue.size(); i++)
    {
        if(queue.at(i) -> getNumberInQueue() == numberInQueue)
            return queue.at(i);
    }
    throw "Polska numeracja dziwna, Arek, wracamy do Sidney, can't stand it any longer";
}

void Shop::serveCustomers() {
    while(isOpen) {
        this_thread::sleep_for(chrono::seconds( SERVING_TIME ));
        shared_ptr<Client> currentClient = queue.at(0);
        currentClient ->buyProducts(*shopAssistant);
        queue.erase(queue.begin());

    }
}

void Shop::simulateClients() {
    srand(time(NULL));
    while(isOpen) {
        this_thread::sleep_for(chrono::seconds(rand() % 10 + 5));

        shared_ptr<Client> cl(new Client(rand() % 4000 + 100));

        int prAmount = rand() % 10 + 2;
        for (int i = 1; i < prAmount; i++)
        {
            cl -> addToCart(
                    products.at(rand() % products.size())
                    );

        }
        queue.push_back(cl);
    }
}

int Shop::getQueueSize() {
    return queue.size();
}

shared_ptr<Client> Shop::getClientFromQueue(int numberInQueue) {
    return queue.at(numberInQueue);
}

shared_ptr<ShopAssistant> Shop::getShopAssistant() {
    return this -> shopAssistant;
}


