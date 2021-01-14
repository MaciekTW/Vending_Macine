//
// Created by Maciek on 16.11.2020.
//

#ifndef AUTOMAT_DRINK_H
#define AUTOMAT_DRINK_H

#include <iostream>
#include <iomanip>
#include "Maintenance.h"

class drink {
    int ID;
    std::string nazwa;
    double cena;
public:
    drink();
    drink( int ID, std::string name, double price );
    int getID();
    std::string getName();
    double getPrice();
    void setID(int ID);
    void setName(std::string name);
    void setPrice(double price);
    friend std::ostream& operator<<(std::ostream& os, const drink& dr);
};


#endif //AUTOMAT_DRINK_H
