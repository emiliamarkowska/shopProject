//
// Created by Arek on 20.01.2019.
//

#include <UserInterface.h>

#include "UserInterface.h"

UserInterface::UserInterface() {
    this -> shop = std::make_shared<Shop> ("Elily&Aurora");

}

void UserInterface::displayClientsInformation() {
    cout << "Total amount of clients: " << this -> shop -> getQueueSize() << endl;
    for (int i = 0 ; i < this -> shop -> getQueueSize(); i++)
    {
        cout << "Client " << i+1 << endl;
        cout << this -> shop -> getClientFromQueue(i) ->getInformation() << endl;
    }
}

void UserInterface::displayProductsInformation() {
    this -> shop -> getInformationAboutProducts();

}

void UserInterface::changeShopState() {
    if (shop -> checkIfOpen())
    {
        cout << "Shop is OPEN. Do you want to close it? y/n" << endl;
        string ans;
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            this -> shop ->changeShopState();
            cout << "Shop is now CLOSED." << endl;
            return;
        }
    }
    else
    {
        cout << "Shop is CLOSED. Do you want to open it? y/n" << endl;
        string ans;
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            this -> shop ->changeShopState();
            cout << "Shop is now OPEN." << endl;
            return;
        }
    }

}

void UserInterface::changeSalary() {
    double amountToChange;
    cout << "Set new salary of shop assistant: ";
    cin >> amountToChange;
    this -> shop -> getShopAssistant() -> setSalary(amountToChange);
    cout << "You have successfully changed assistant's salary to $" << shop -> getShopAssistant() -> getSalary() << endl;
}

void UserInterface::buyProducts() {
    cout <<"Good Morning, welcome in BuyProductsToYourShop service, we will do anything to satisfy your current needs, we offer very large choice of goods" << endl;
    cout << "Which one of those you would like to buy?" << endl << endl;
    cout << "1. Carrot - $1" << endl;
    cout << "2. Bread - $0.75" << endl;
    cout << "3. Chicken - $5" << endl;
    cout << "4. T-Shirt - $20" << endl;
    cout << "5. Shoes - $70" << endl;
    cout << "6. Jeans - $60" << endl;
    cout << "7. Smartphone - $700" << endl;
    cout << "8. TV - $3600" << endl;

    int choice;
    cin >> choice;
    cout << "How many items do you want to buy?" << endl;
    int amount;
    cin >> amount;
    shared_ptr<Product> product;
    switch (choice)
    {
        case 1:
            product = std::make_shared<Food> (2, "Carrot", 20);
            shop ->withdrawMoney(1 * amount);
            break;
        case 2:
            product = std::make_shared<Food> (1.5, "Bread", 3);
            shop ->withdrawMoney(0.75 * amount);
            break;
        case 3:
            product = std::make_shared<Food> (10, "Chicken", 10);
            shop ->withdrawMoney(5* amount);
            break;
        case 4:
            product = std::make_shared<Clothes> (40, "T-Shirt", 36);
            shop ->withdrawMoney(20 * amount );
            break;
        case 5:
            product = std::make_shared<Clothes> (100, "Shoes", 40);
            shop ->withdrawMoney(70 * amount);
            break;
        case 6:
            product = std::make_shared<Clothes> (80, "Jeans", 38);
            shop ->withdrawMoney(60 * amount);
            break;
        case 7:
            product = std::make_shared<Electronics> (800, "Smartphone", 2);
            shop ->withdrawMoney(700 * amount);
            break;
        case 8:
            product = std::make_shared<Electronics> (4000, "TV", 3);
            shop ->withdrawMoney(3600 * amount);
            break;
        default:
            return;
    }

    if(amount * product ->getPrice() > shop -> getBudget())
    {
        cout << "You can't buy those things" << endl;
        return;
    }

    for(int i = 0; i < amount; i++)
    {
        shop -> addProduct(product);
    }
    cout << "Your product has been bought." << endl;
}

void UserInterface::withdrawMoney() {
    cout << "How much money you would like to withdraw?" << endl;
    cout << "Amount: ";
    double amount;
    cin >> amount;
    cout << "You have withdrawn $" << shop -> withdrawMoney(amount);
}

void UserInterface::checkMoneyState() {
    cout << "Current shop balance: " << shop ->getBudget() << endl;
}

void UserInterface::displayMenu() {
    int answ = 0;
    do  {
        cout << "1. Open/Close shop" << endl;
        cout << "2. Show clients in the queue" << endl;
        cout << "3. Display products currently in the shop" << endl;
        cout << "4. Modify salary of the Shop Assistant" << endl;
        cout << "5. Buy products for your shop" << endl;
        cout << "6. Check balance" << endl;
        cout << "7. Withdraw money from cash register" << endl;
        cout << "8. Quit" << endl << endl;
        cout << "Option: ";
        cin >> answ;

        switch(answ)
        {
            case 1:
                changeShopState();
                break;
            case 2:
                displayClientsInformation();
                break;
            case 3:
                displayProductsInformation();
                break;
            case 4:
                changeSalary();
                break;
            case 5:
                buyProducts();
                break;
            case 6:
                checkMoneyState();
                break;
            case 7:
                withdrawMoney();
                break;
            case 8:
                cout << "Closing..." << endl;
                break;
            default:
                break;
        }
    } while (answ != 8);
}

void UserInterface::start() {
    cout << "Welcome to " << shop -> getShopName() << "." << endl;
    cout << "Here are your options:" << endl;
    displayMenu();
}
