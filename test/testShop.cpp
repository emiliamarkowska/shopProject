//
// Created by Emila on 2019-01-20.
//

#include <boost/test/unit_test.hpp>
#include "Shop.h"
BOOST_AUTO_TEST_SUITE(ShopTesting)
BOOST_AUTO_TEST_CASE(CheckingShopState){

    shared_ptr<Shop> shop(new Shop("Pillow"));
    BOOST_CHECK_EQUAL(shop -> getAmountOfProducts(), 160);
    BOOST_CHECK_EQUAL(shop -> checkIfOpen() , false);
    BOOST_CHECK_EQUAL(shop -> getBudget() , 10000);
    shop -> addMoney(1000);
    BOOST_CHECK_EQUAL(shop -> getBudget(), 11000);
    shop -> withdrawMoney(1000);
    BOOST_CHECK_EQUAL(shop -> getBudget(), 10000);
    BOOST_CHECK_EQUAL(shop -> getQueueSize(), 0);
    }


BOOST_AUTO_TEST_SUITE_END()