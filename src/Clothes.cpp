//
// Created by Arek on 20.01.2019.
//


#include "Clothes.h"

Clothes::Clothes(double price, string name, int size) : Product(price, name)  {
    this -> size = size;
}

string Clothes::showDescription() {
    ostringstream str;
    str << "Product type: clothing" << endl;
    str << "size: " << getSize() << endl << endl;
    return str.str();
}

int Clothes::getSize() {
    return this -> size;
}
