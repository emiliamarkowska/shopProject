//
// Created by Emila on 2019-01-21.
//

//
// Created by Emila on 2019-01-20.
//

#include <boost/test/unit_test.hpp>
#include "Shop.h"
BOOST_AUTO_TEST_SUITE(ShopTesting)
BOOST_AUTO_TEST_CASE(CheckingShopAssistantState){

    shared_ptr<Food> meat (new Food(20, "meat", 3));
    shared_ptr<Food> eggs (new Food(10, "eggs", 10));
    shared_ptr<Clothes> skirt (new Clothes(50, "skirt", 36));
    shared_ptr<Clothes> flippers (new Clothes(15, "flippers", 40));
    shared_ptr<Electronics> TV (new Electronics(3000, "TV", 4));
    shared_ptr<Electronics> headphones (new Electronics(55, "headphones", 3));

   vector<shared_ptr<Product>> productsToBuy;
   productsToBuy.push_back(meat);
   productsToBuy.push_back(eggs);
   productsToBuy.push_back(skirt);
   productsToBuy.push_back(flippers);
   productsToBuy.push_back(TV);
   productsToBuy.push_back(headphones);

   Shop* shop (new Shop("ABCD"));
   shared_ptr<ShopAssistant> shopAssistant1 (new ShopAssistant("John", 1, 2000, shop ));
   shop -> hireShopAssistant(shopAssistant1);

    BOOST_CHECK_EQUAL(shop -> getShopAssistant() -> sell(productsToBuy) , 3150);
    BOOST_CHECK_EQUAL(shop -> getBudget() , 13150);
    delete shop;
}


BOOST_AUTO_TEST_SUITE_END()//
// Created by Emila on 2019-01-21.
//

