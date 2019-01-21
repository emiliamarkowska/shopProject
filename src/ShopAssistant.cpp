//
// Created by Arek on 20.01.2019.
//

#include <ShopAssistant.h>

#include "ShopAssistant.h"
#include <Shop.h>
#include<iostream>

const int SERVING_TIME = 3000;

ShopAssistant::ShopAssistant(string name, int id, double salary, Shop* shop) {
    this -> name = name;
    this -> id = id;
    this -> salary = salary;
    this -> shop = shop;

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

void ShopAssistant::setSalary(double amountToChange) {
    this -> salary = amountToChange;
    cout << "New serving speed: " << SERVING_TIME / amountToChange << "s." << endl;
}
