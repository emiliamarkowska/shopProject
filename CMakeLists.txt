cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_VERBOSE_MAKEFILE TRUE) 

#Source files here
set(SOURCE_FILES
        src/main.cpp
        src/Product.cpp
        include/Product.h
        src/Shop.cpp
        include/Shop.h
        src/UserInterface.cpp
        include/UserInterface.h
        src/Client.cpp
        include/Client.h
        src/ShopAssistant.cpp
        include/ShopAssistant.h
        src/Food.cpp
        include/Food.h
        src/Clothes.cpp
        include/Clothes.h
        src/Electronics.cpp
        include/Electronics.h)

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)

#TESTs
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        test/testShop.cpp
        src/Shop.cpp
        src/Product.cpp
        src/Client.cpp
        src/Food.cpp
        src/Electronics.cpp
        src/Clothes.cpp
        src/ShopAssistant.cpp
        test/testClient.cpp test/testShopAssistant.cpp)

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})