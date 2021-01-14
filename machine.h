//
// Created by Maciek on 16.11.2020.
//

#ifndef AUTOMAT_MACHINE_H
#define AUTOMAT_MACHINE_H

#include "Maintenance.h"
#include "drink.h"
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include "PaymentMethodContainer.h"
#include "Service.h"

#define ARRAY_SIZE 18
#define MACHINE_SIZE 21
#define KEYPAD_START 5
#define KEYPAD_STOP 16
#define PRECISION 0.0001
class machine {
    std::vector<int> amount;
    int page;
    //Methods that shouldn't be used outside the class
    bool findPos( int x, std::vector<drink> stock, int &pos, int size );
    std::string print( int& index, std::string id, std::string price="ORDER");
    Service serviceObj;
public:
    machine();
    machine( int size, std::vector<int> tab );
    ~machine();


    bool christmasGift(std::string name, int pos);
    std::vector<int> getAmount();
    void setAmount( int size, std::vector<int> &tab );
    void setPage(int page);
    int getPage();
    void print( std::vector<drink> stock, int size, std::string id="-",std::string price="ORDER");
    bool change( std::vector<drink>& stock, int size, int &pos );
    bool pay( PaymentMethodContainer& payment,int choice,std::vector<drink> stock, int size,int pos);
    bool sold( double price, int pos,std::vector<drink> stock);
    bool stop();
    void pageUp() { page++; }
    void pageDown(){ if( page > 1 ) page--; }
    void setPrice(PaymentMethodContainer& payment,float price,int method);
};

#endif //AUTOMAT_MACHINE_H
