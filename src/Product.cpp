//
// Created by Emila on 2019-01-19.
//

#include "Product.h"

Product::Product(double price, string name) {
    this -> price = price;
    this -> name = name;
}

int Product::getSize() {
    throw "Product is not clothing type";
}

int Product::getDaysDueExpiration() {
    throw "Product is not food type";
}

int Product::getWarrantyPeriod() {
    throw "Product is not electronics type";
}

void Product::setWarrantyPeriod(int period) {
    throw "Product is not electronics type";
}

double Product::getPrice() {
    return this->price;
}

void Product::setPrice(double price) {
    this -> price = price;
}

string Product::getName() {
    return this -> name;
}
