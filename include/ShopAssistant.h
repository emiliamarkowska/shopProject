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
    shared_ptr<Shop> shop;
public:
    ShopAssistant(string name, int id, double salary);
    double sell (vector<shared_ptr<Product>> products);
    double getSalary();
    string getName();
    int getID();
    void setID(int id);

};


#endif //PROJECT_SHOPASSISTANT_H
