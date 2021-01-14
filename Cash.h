//
// Created by Maciek on 17.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_CASH_H
#define TWAROGMACIEJ_ETAP1_CASH_H
#include <cmath>
#include "Platnosc.h"

class Cash : public Platnosc {
    std::string name;
public:
    Cash();
    Cash(std::string name);
    bool pay();
};


#endif //TWAROGMACIEJ_ETAP1_CASH_H
