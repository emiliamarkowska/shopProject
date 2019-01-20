//
// Created by Arek on 20.01.2019.
//

#include <Food.h>

#include "Food.h"

Food::Food(double price, string name, int daysDueExpiration) : Product(price, name) {
    this -> daysDueExpiration = daysDueExpiration;
}

string Food::showDescription() {
    ostringstream str;
    str << "Product type: food" << endl;
    str << "days due expiration: " << getDaysDueExpiration() << " days" << endl << endl;
    return str.str();
}

int Food::getDaysDueExpiration() {
    return this -> daysDueExpiration;
}
