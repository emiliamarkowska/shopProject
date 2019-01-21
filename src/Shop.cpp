//
// Created by Arek on 20.01.2019.
//

#include <Shop.h>

#include "Shop.h"
#include "iostream"
#include <time.h>


const int SERVING_TIME = 3000;

Shop::Shop(string shopName) {
    this -> shopName = shopName;
    this -> shopAssistant = std::make_shared<ShopAssistant> ("John", 1, 300, this);
    this -> isOpen = false;
    this -> budget = 10000;

    for (int i = 0; i < 500; i++)
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
struct NameWithAmount{
    string name;
    int amount;

    NameWithAmount(string name)
    {
        this -> name = name;
        this -> amount = 1;
    }

};


void Shop::getInformationAboutProducts() {
    int count = 0;
    vector<shared_ptr<NameWithAmount>> namesWithAmounts;

    if(products.size() == 0)
    {
        cout << "No products in shop" << endl;
        return;
    }

    namesWithAmounts.push_back(make_shared<NameWithAmount>(products.at(0) -> getName()));
    cout << "Products total: " << products.size() << endl;
    for(int i = 1; i < products.size() ; i++)
    {
        bool isAlready = false;
        for(int j = 0; j < namesWithAmounts.size(); j++)
        {
            if(namesWithAmounts.at(j) -> name == products.at(i) -> getName())
            {
                namesWithAmounts.at(j) -> amount++;
                isAlready = true;
            }
        }
        if(!isAlready)
            namesWithAmounts.push_back(make_shared<NameWithAmount>(products.at(i) -> getName()));
    }

    for(int i = 0; i < namesWithAmounts.size(); i++)
    {
        cout << "Name: " << namesWithAmounts.at(i) -> name << endl;
        cout << "Amount: " << namesWithAmounts.at(i) -> amount << endl << endl;
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
        staffTh.join();
    }
    else {
        this->isOpen = true;
        staffTh = std::thread(&Shop::serveCustomers, this);
        clientsTh = std::thread(&Shop::simulateClients, this);

    }
}

double Shop::getBudget() {
    return this -> budget;
}

void Shop::addMoney(double money) {
       budget += money;
}

double Shop::withdrawMoney(double money) {
    try{
        if(budget - money >= 0)
        {
            budget -= money;
            return money;
        }
        throw "You want to withdraw too much money";
    }
   catch(char const* e)
   {
       cout << e  << endl;
   }

}

shared_ptr<Product> Shop::getProduct(string name) {
    for(int i = 0; i < products.size(); i++)
    {
        if(products.at(i) -> getName() == name)
            return products.at(i);
    }

    throw "There is no product with such name";
}


shared_ptr<Client> Shop::getClient(unsigned numberInQueue) {
    for(int i = 0; i < queue.size(); i++)
    {
        if(queue.at(i) -> getNumberInQueue() == numberInQueue)
            return queue.at(i);
    }
    throw "There is no client with such number in a queue";
}

void Shop::serveCustomers() {

    while(isOpen) {
        int st = SERVING_TIME / shopAssistant -> getSalary();
        this_thread::sleep_for(chrono::seconds( st ));
        if (queue.size() > 0) {

            shared_ptr<Client> currentClient = queue.at(0);
            currentClient->buyProducts(*shopAssistant);
            queue.erase(queue.begin());
            withdrawMoney(shopAssistant -> getSalary());
        }
    }
}

void Shop::simulateClients() {
    srand(time(NULL));
    while(isOpen)
    {
        this_thread::sleep_for(chrono::seconds(rand() % 10 + 5));
       shared_ptr<Client> cl(new Client(rand() % 4000 + 100));

        int prAmount = rand() % 10 + 2;
        for (int i = 1; i < prAmount; i++)
        {
            int randomPosition = rand() % products.size() ;
            cl -> addToCart(
                    products.at(randomPosition)
                    );
            products.erase(products.begin() + randomPosition);
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

void Shop::addProduct(shared_ptr<Product> product) {
    for (int i = 0; i < products.size(); i++)
    {
        if (product -> getName() == products.at(i) -> getName())
        {
            products.insert(products.begin() + i, product );
            return;
        }
    }
    products.push_back(product);
}

string Shop::getShopName() {
    return this -> shopName;
}

int Shop::getAmountOfProducts() {
    return products.size();
}

void Shop::hireShopAssistant(shared_ptr<ShopAssistant> shopAssistant) {
    this -> shopAssistant = shopAssistant;
}




