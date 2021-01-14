//
// Created by Maciek on 13.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_KARTA_H
#define TWAROGMACIEJ_ETAP1_KARTA_H

#include "Platnosc.h"




class Karta:public Platnosc {
    std::string number;
    int cid;
    float balance;
    int pin;

public:
    Karta();
    Karta(std::string number, int cid, float balance, int pin);
    void setPin(int pin);
    int getPin()
    { return pin; }
    void setBalance(float balance);
    float getBalance()
    { return balance; }
    void setCid(int cid);
    int getCid() { return cid; }
    void setNumber(std::string number);
    std::string getNumber(){ return number; }
    bool check();
    bool pay();

};


#endif //TWAROGMACIEJ_ETAP1_KARTA_H
