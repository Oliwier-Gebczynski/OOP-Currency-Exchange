cmake_minimum_required(VERSION 3.25)
project(OOP_Currency_Exchange)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_Currency_Exchange
        main.cpp
        main.h class/wallet.h class/wallet.cpp class/currency.h class/currency.cpp class/admin.h class/admin.cpp class/user.h class/user.cpp class/dataOperator.h class/dataOperator.cpp)
