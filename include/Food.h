//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_FOOD_H
#define PROJECT_FOOD_H
#include <Product.h>

class Food : public Product {
private:
    int daysDueExpiration;
public:
    Food(double price, string name, int daysDueExpiration);
    virtual string showDescription();
    int getDaysDueExpiration();
};


#endif //PROJECT_FOOD_H
