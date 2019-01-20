//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_ELECTRONICS_H
#define PROJECT_ELECTRONICS_H
#include <Product.h>

class Electronics : public Product {
private:
    int warrantyPeriodInYears;
public:
    Electronics(double price, string name, int warranty);
    virtual string showDescription();
    int getWarrantyPeriod();
    void setWarrantyPeriod(int period);


};


#endif //PROJECT_ELECTRONICS_H
