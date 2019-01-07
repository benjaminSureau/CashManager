cmake_minimum_required(VERSION 3.9)
project(CashManagerServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(CashManagerServer
        CashManager.pro
        CashManager.pro.user
        categorie.cpp
        categorie.h
        facture.cpp
        facture.h
        listener.cpp
        listener.h
        main.cpp
        product.cpp
        product.h)
