//
// Created by Emila on 2019-01-19.
//

#ifndef PROJECT_PRODUCT_H
#define PROJECT_PRODUCT_H

#include <string>
#include <sstream>
using namespace std;


class Product {

protected:
    double price;
    string name;

public:
    Product(double price, string name);
    virtual string showDescription() = 0;
    int getSize();
    int getDaysDueExpiration();
    int getWarrantyPeriod();
    void setWarrantyPeriod(int period);
    double getPrice();
    void setPrice(double price);
    string getName();

};


#endif //PROJECT_PRODUCT_H
