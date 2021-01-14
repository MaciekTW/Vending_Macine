//
// Created by Maciek on 18.12.2020.
//

#ifndef TWAROGMACIEJ_ETAP1_MAINTENANCE_H
#define TWAROGMACIEJ_ETAP1_MAINTENANCE_H
#include <iostream>
#include <iomanip>

#define INDEX_ERROR -1
#define PRICE_ERROR -5

class Maintenance {
public:
    void clear(int n=100);
    void bufforFix();
    void ErrorBox();
    void ChristmasBox();
};
struct WrongName : public std::exception
{
    const char * what() const throw()
    {
        return "ERROR: Wrong name provided";
    }
};
struct WrongPrice : public std::exception
{
    const char * what () const throw ()
    {
        return "ERROR: Wrong price provided";
    }
};
struct WrongID : public std::exception
{
    const char * what () const throw ()
    {
        return "ERROR: Wrong ID provided";
    }
};
struct FileError : public std::exception
{
    const char * what () const throw ()
    {
        return "ERROR: Wrong file provided";
    }
};
#endif //TWAROGMACIEJ_ETAP1_MAINTENANCE_H
