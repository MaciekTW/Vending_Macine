//
// Created by Maciek on 17.12.2020.
//

#include "PaymentMethodContainer.h"

Maintenance maintenanceObj3;
PaymentMethodContainer::PaymentMethodContainer( Blik& blik)
{
    this->blik = blik;
    isBlik = true;
}

PaymentMethodContainer::PaymentMethodContainer( Cash& cash)
{
    this->cash = cash;
    isCash = true;
}

PaymentMethodContainer::PaymentMethodContainer( Karta& cart)
{
    this->cart = cart;
    isCart = true;
}

PaymentMethodContainer::PaymentMethodContainer( Cash& cash, Blik& blik, Karta& cart)
{
    this->blik = blik;
    this->cash = cash;
    this->cart = cart;
    isCash = true;
    isBlik = true;
    isCart = true;
}

PaymentMethodContainer::PaymentMethodContainer( Cash& cash, Karta& cart)
{
    this->cash = cash;
    this->cart = cart;
    isCash = true;
    isCart = true;
}

PaymentMethodContainer::PaymentMethodContainer( Karta& cart, Blik& blik)
{
    this->blik = blik;
    this->cart = cart;
    isBlik = true;
    isCart = true;
}
int PaymentMethodContainer::printMethods()
{
    int i = 1;
    int blikIndex=-1;
    int cartIndex=-1;
    int cashIndex=-1;
    if( isCash )
    {
        std::cout << i << ". Cash" << std::endl;
        cashIndex = i++;
    }
    if( isBlik )
    {
        std::cout << i << ". Blik" << std::endl;
        blikIndex = i++;
    }
    if( isCart )
    {
        std::cout << i << ". Credit Card" << std::endl;
        cartIndex = i++;
    }
    if( !isCart && !isBlik && !isCash )
    {
        std::cout << "ERROR: No available payment methods! Try again later!" << std::endl;
        return PAYMENT_ERROR;
    }

    std::cout << "Method[put a number]: ";
    int x;
    if( !( std::cin >> x ) || x >= i )            //Protection against non-numeric input
    {
        maintenanceObj3.bufforFix();
        std::cout << "ERROR: No such payment method!" << std::endl;
        return printMethods();

    }
    if( x == cashIndex )
        return 1;
    else if( x == blikIndex )
        return 2;
    else if( x == cartIndex )
        return 3;
    else
        return INDEX_ERROR;
}
Cash PaymentMethodContainer::getCash()
{
    return cash;
}
Karta PaymentMethodContainer::getCart()
{
    return cart;
}

Blik PaymentMethodContainer::getBlik()
{
    return blik;
}
float PaymentMethodContainer::getAmount(int method)
{
    switch( method )
    {
        case 1: return cash.getAmount(); break;
        case 2: return blik.getAmount(); break;
        case 3: return cart.getAmount(); break;
        default:  return 0;
    }

}