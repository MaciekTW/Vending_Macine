//
// Created by Maciek on 17.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_PAYMENTMETHODCONTAINER_H
#define TWAROGMACIEJ_ETAP1_PAYMENTMETHODCONTAINER_H

#include "Blik.h"
#include "Cash.h"
#include "Karta.h"
#include "Maintenance.h"


class PaymentMethodContainer {
    friend class machine;
    int methodsNumber=1;
    Blik blik;
    Cash cash;
    Karta cart;
    bool isBlik=false;
    bool isCart=false;
    bool isCash=false;
public:
    PaymentMethodContainer(Blik& blik);
    PaymentMethodContainer(Cash& cash);
    PaymentMethodContainer(Karta& cart);
    PaymentMethodContainer(Cash& cash, Blik& blik, Karta& cart);
    PaymentMethodContainer(Cash& cash, Karta& cart);
    PaymentMethodContainer(Karta& cart, Blik& blik);
    int printMethods();
    float getAmount(int Method);
    Cash getCash();
    Karta getCart();
    Blik getBlik();
    template<class T1>
    bool MethodChoose( T1 & line1 )
    {
        return line1.pay();
    }

};


#endif //TWAROGMACIEJ_ETAP1_PAYMENTMETHODCONTAINER_H
