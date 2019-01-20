//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_CLOTHES_H
#define PROJECT_CLOTHES_H
#include "Product.h"

class Clothes : public Product {
private:
    int size;
public:
    Clothes(double price, string name, int size);
    virtual string showDescription();
    virtual int getSize();


};


#endif //PROJECT_CLOTHES_H
