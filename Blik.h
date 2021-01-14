//
// Created by Maciek on 17.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_BLIK_H
#define TWAROGMACIEJ_ETAP1_BLIK_H
#include "Platnosc.h"
#include <random>

class Blik : public Platnosc{
    float balance;
    long int code=0;
    std::string accountOwner;
public:

    Blik();
    Blik(std::string accountNumber,float balance);
    void draw();
    bool pay();
    void generateCode();
    long int getCode();
    std::string getAccountOwver() {return accountOwner;};
};


#endif //TWAROGMACIEJ_ETAP1_BLIK_H
