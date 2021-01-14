//
// Created by Maciek on 17.12.2020.
//

#include "Cash.h"

Maintenance service;
bool Cash::pay()
{
    double temp;
    print();
    std::cout << "Put a coin: ";
    if( !( std::cin >> temp ) )     //Protection against non-numeric input
        service.bufforFix();
    if( temp != 1 && temp != 2 && temp != 5 && temp != 10 && temp != 20 && temp != 50 )
    {
        std::cout << "There is no such coin! Try again" << std::endl;
        return pay();
    }
    if( temp == 1 || temp == 2 || temp == 5 )
        temp *= 100;
    if( temp > round( amount * 100 ) )
    {
        std::cout << "It is too much!" << std::endl;
        return pay();
    }

    temp /= 100;
    amount -= temp;

    return true;
}
Cash::Cash()
{
    Cash("Maciek");
}
Cash::Cash( std::string name )
{
    this->name=name;
}
