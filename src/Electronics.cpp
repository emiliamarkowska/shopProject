//
// Created by Arek on 20.01.2019.
//

#include <Electronics.h>

#include "Electronics.h"

Electronics::Electronics(double price, string name, int warranty) : Product(price, name) {
    this -> warrantyPeriodInYears = warranty;
}

string Electronics::showDescription() {
    ostringstream str;
    str << "Product type: electronics" << endl;
    str << "Name: " << getName() << endl;
    str << "Price: " << getPrice() << endl;
    str << "warranty period: " << getWarrantyPeriod() << " years" << endl << endl;
    return str.str();
}

int Electronics::getWarrantyPeriod() {
    return this -> warrantyPeriodInYears;
}

void Electronics::setWarrantyPeriod(int period) {
    this -> warrantyPeriodInYears = period;
}
