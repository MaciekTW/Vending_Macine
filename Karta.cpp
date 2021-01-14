//
// Created by Maciek on 13.12.2020.
//

#include "Karta.h"

Karta::Karta()
{
    Karta( "20 2000 20000 2000", 235, 124.87, 1234 );
}


Karta::Karta( std::string number, int cid, float balance, int pin )
{
    this->number=number;
    this->cid = cid;
    this->pin=pin;
    this->balance=balance;

}

void Karta::setPin( int pin )
{
    this->pin = pin;
}

void Karta::setBalance( float balance )
{
    if( balance >= 0 )
        this->balance = balance;
    else
    {
        std::cout << "Wrong value";
        this->balance = 0;
    }
}

void Karta::setCid( int cid )
{
    if( cid >= 100 && cid < 1000 )
        this->cid = cid;
    else
    {
        std::cout << "Wrong cid number";
        this->cid = 111;
    }
}

void Karta::setNumber( std::string number )
{
    this->number = number;
}

bool Karta::check()
{
    return false;
}

bool Karta::pay()
{
    std::cout << "Payment by credit card in progress" << std::endl;
    int pinCode;

    for( int i = 3; i > 0; i-- )
    {
        std::cout << "Please enter the pin code[Default 1234]: ";
        if(!(std::cin >> pinCode))
        {
            std::cout<<"ERROR: PIN CANNOT BE A TEXT"<<std::endl;
            mnObj.bufforFix();
        }
        if( pin != pinCode )
        {
            std::cout << "Wrong pin !!!! You have " << i-1 << " attempts left" << std::endl;
        }
        else
            break;

        if(i == 1)
            return false;
    }
    if( amount > balance )
    {
        std::cout << "Sorry your card balance is too low :((" << std::endl;
        return false;
    }

    balance-=amount;
    amount=0;
    return true;
}

