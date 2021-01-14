//
// Created by Maciek on 06.01.2021.
//

#ifndef TWAROGMACIEJ_ETAP3_SERVICE_H
#define TWAROGMACIEJ_ETAP3_SERVICE_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Maintenance.h"
#include "drink.h"

class Service {
    std::vector<int> temp;
    double balance;
    std::vector<int>& stock=temp;
    int soldAmount;
    int uniqueDrinks;
    std::fstream logFile;
public:
    Service();
    Service(double balance,std::vector<int> &saldo,int soldAmount,int drinks);
    void printSummary();
    double getBalance();
    void setBalance(double saldo);
    std::vector<int> getAmount();
    void setAmount(std::vector<int> &saldo);
    bool checkID(std::vector<drink> & stock,int id);
    void increaseBalance(double sum);
    void increaseSoldAmount();
    void serviceUpdate(double price,std::vector<int> &temp);
    int drinksLeft();
    int bottlesLeft();
    void fileOpen(std::string fileName);
    void showLogs();
    void serviceMenu(std::vector<drink>& stock);
    void machineRefillMenu(std::vector<drink> stock);
    void refill(int pos, std::string name);
    void refill(int pos, std::vector<int> ids);
    void addItem(std::vector<drink>& drinks);
    void priceChange(std::vector<drink>& drinks);
    static bool stop();
    template<class T1, class T2, class T3, class T4>
    void LogWrite( T1 line1, T2 line2="", T3 line3="", T4 line4="")
    {
        fileOpen("LogFile.txt");
        std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());
        std::string DATE= std::string {std::ctime( &time)};
        DATE.pop_back();            //we have to get rid of \n at the end of date
        logFile <<"["<< DATE <<"]: ";
        logFile <<line1<<" "<<line2<<" "<<line3<<" "<<line4<<std::endl;
        logFile.close();
    }


};

#endif //TWAROGMACIEJ_ETAP3_SERVICE_H
