//
// Created by Maciek on 15.12.2020.
//

#include "Platnosc.h"

float Platnosc::getAmount()
{
    return amount;
}

void Platnosc::setAmount( float amount )
{
    this->amount = amount;
}

void Platnosc::print()
{
    std::cout << "Left to pay: " << amount << " zl" << std::endl;
}


