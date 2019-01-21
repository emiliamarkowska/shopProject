//
// Created by Emila on 2019-01-21.
//

//
// Created by Emila on 2019-01-20.
//

#include <boost/test/unit_test.hpp>
#include "Shop.h"
BOOST_AUTO_TEST_SUITE(ShopTesting)
BOOST_AUTO_TEST_CASE(CheckingClientState){

    shared_ptr<Food> meat (new Food(20, "meat", 3));
    shared_ptr<Food> eggs (new Food(10, "eggs", 10));
    shared_ptr<Clothes> skirt (new Clothes(50, "skirt", 36));
    shared_ptr<Clothes> flippers (new Clothes(15, "flippers", 40));
    shared_ptr<Electronics> TV (new Electronics(3000, "TV", 4));
    shared_ptr<Electronics> headphones (new Electronics(55, "headphones", 3));

    shared_ptr<Client> client1(new Client(4000));
    client1 -> addToCart(meat);
    client1 -> addToCart(eggs);
    client1 -> addToCart(skirt);
    client1 -> addToCart(flippers);
    client1 -> addToCart(TV);
    client1 -> addToCart(headphones);

    BOOST_CHECK_EQUAL(client1 -> currentCost(), 3150);
    BOOST_CHECK_EQUAL(client1 -> getCartSize(), 6);

    client1 -> removeFromCart(TV);

    BOOST_CHECK_EQUAL(client1 -> currentCost(), 150);
    BOOST_CHECK_EQUAL(client1 -> getCartSize(), 5);





}


BOOST_AUTO_TEST_SUITE_END()