//
// Created by Maciek on 15.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_Platnosc_H
#define TWAROGMACIEJ_ETAP1_Platnosc_H

#define PAYMENT_ERROR -1;
#include <iostream>
#include <iomanip>
#include "Maintenance.h"

class Platnosc {
protected:
    float amount;
    Maintenance mnObj;
public:
    float getAmount();
    void print();
    void setAmount(float amount);
};


#endif //TWAROGMACIEJ_ETAP1_PAYMENTMETHODCONTAINER_H
