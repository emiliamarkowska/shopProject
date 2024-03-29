//
// Created by Arek on 20.01.2019.
//

#include <Client.h>
#include "iostream"

using namespace std;

void Client::addToCart(shared_ptr<Product> product) {

    if (currentCost() + product -> getPrice() <= getMoney())
    {

        shoppingCart.push_back(product);

    }

}

void Client::buyProducts(ShopAssistant sa) {

    pay(sa.sell(shoppingCart));

}

double Client::getMoney() {
    return this -> money;
}

void Client::addMoney(double amount) {
 money += amount;
}

void Client::pay(double amount) {
money -= amount;
}

Client::Client(double money) {
    this -> money = money;
}

double Client::currentCost() {
    double cost = 0;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        cost += shoppingCart.at(i) -> getPrice();
    }
    return cost;
}

void Client::removeFromCart(shared_ptr<Product> product) {
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        if (product == shoppingCart.at(i)) {
            shoppingCart.erase(shoppingCart.begin() + i);
            return;
        }
    }
    cout << "Product not in the cart" << endl;
}

unsigned Client::getNumberInQueue() {
    return this -> numberInQueue;
}

string Client::getInformation() {
    ostringstream information;
    information << "Cart content: " << endl;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        information << i+1 << ". " << shoppingCart.at(i) -> showDescription() << endl;
    }

    information << "Total cost: " << currentCost() << endl;
    return information.str();
}

int Client::getCartSize() {
    return shoppingCart.size();
}
