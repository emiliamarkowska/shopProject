//
// Created by Arek on 20.01.2019.
//

#include <ShopAssistant.h>

#include "ShopAssistant.h"
#include <Shop.h>

ShopAssistant::ShopAssistant(string name, int id, double salary) {
    this -> name = name;
    this -> id = id;
    this -> salary = salary;
}

double ShopAssistant::sell(vector<shared_ptr<Product>> products) {

    double sum = 0;
    for (int i = 0; i < products.size(); i++)
    {
        sum += products.at(i) -> getPrice();
    }
    shop -> addMoney(sum);

    return sum;
}

double ShopAssistant::getSalary() {
    return this -> salary;
}

string ShopAssistant::getName() {
    return this -> name;
}

int ShopAssistant::getID() {
    return this -> id;
}

void ShopAssistant::setID(int id) {
    this -> id = id;
}
