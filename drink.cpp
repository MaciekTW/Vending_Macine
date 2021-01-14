//
// Created by Maciek on 16.11.2020.
//

#include "drink.h"

drink::drink() : drink( 0, "NaN", 0 )
{
}

drink::drink( int ID, std::string name, double price )
{
    try
    {
        setName( name );
        setPrice( price );
        setID( ID );
    }catch(WrongPrice & arg)
    {
        std::cout<<"Wrong price of a drink"<<std::endl;
        exit(-1);
    }
}

int drink::getID()
{
    return ID;
}

std::string drink::getName()
{
    return nazwa;
}

double drink::getPrice()
{
    return cena;
}

void drink::setID( int ID )
{
    this->ID = ID;
}

void drink::setName( std::string name )
{
    this->nazwa = name;
}

void drink::setPrice( double price )
{
    if(price < 0)
        throw WrongPrice();


    this->cena = price;
}

std::ostream &operator<<( std::ostream &os, const drink &dr )
{
    os << std::left << "|###| ID: " << std::setw( 3 ) << dr.ID
       << "Product: " << std::setw( 16 ) << dr.nazwa << std::setprecision( 2 )
       << "Price: " << std::setw( 7 ) << dr.cena;
    return os;
}


