//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_SHOPASSISTANT_H
#define PROJECT_SHOPASSISTANT_H

#include <Product.h>
#include <vector>
#include <memory>
//#include <Shop.h>

class Shop;

class ShopAssistant {
private:
    string name;
    int id;
    double salary;
    Shop* shop;
public:
    ShopAssistant(string name, int id, double salary, Shop* shop);
    double sell (vector<shared_ptr<Product>> products);
    double getSalary();
    string getName();
    int getID();
    void setID(int id);
    void setSalary(double amountToChange);

};


#endif //PROJECT_SHOPASSISTANT_H
