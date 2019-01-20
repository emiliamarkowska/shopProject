//
// Created by Arek on 20.01.2019.
//

#ifndef PROJECT_USERINTERFACE_H
#define PROJECT_USERINTERFACE_H

#include "Shop.h"

class UserInterface {
private:
    shared_ptr<Shop> shop;
public:
    UserInterface(shared_ptr<Shop> shop);
    

};


#endif //PROJECT_USERINTERFACE_H
