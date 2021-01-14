//
// Created by Maciek on 17.12.2020.
//

#include "Blik.h"
Maintenance maintenanceObj2;

Blik::Blik()
{
    Blik( "20 2000 20000 20000", 100.00 );
}

Blik::Blik( std::string accountOwner, float balance )
{
    this->accountOwner = accountOwner;
    this->balance = balance;
}

bool Blik::pay()
{
    maintenanceObj2.clear();
    generateCode();
    std::cout << "Payment by BLIK in progress" << std::endl;
    int blikCode;

    draw();
    std::cout << "Please enter the code from your bank mobile app: ";
    if(!(std::cin>>blikCode))
    {
        maintenanceObj2.bufforFix();

    }
    if( code != blikCode )
    {
        std::cout << "Wrong code !!!! " << std::endl;
        return false;
    }

    if( amount > balance )
    {
        std::cout << "Sorry your account balance is too low :((" << std::endl;
        return false;
    }
    balance -= amount;
    amount = 0;
    return true;
}

void Blik::generateCode()
{
    std::random_device rd;
    std::mt19937 mt( rd() );
    std::uniform_real_distribution<long double> dist( 100000000, 999999999 );
    code = static_cast<long int>(dist( mt ));
}

long int Blik::getCode()
{
    return code;
}

void Blik::draw()
{

    std::string owner ="  | | OWNER:";
    std::string balanceString ="  | | BALANCE:";
    std::string codeString =   "  | | CODE:";
    std::string mobile="                          .--.\n"
                       "                          |  |\n"
                       "                          |  |\n"
                       "                          |  |\n"
                       "                          |  |\n"
                       "         _.-----------._  |  |\n"
                       "      .-'               `-.  |\n"
                       "    .'                     `.|\n"
                       "   ;                         |\n"
                       "   |                         |\n"
                       "   |                         |\n"
                       "   |   M A C I E K R O L A   |\n"
                       "   | .---------------------. |\n"
                       "   | | LIMABANK MOBILE APP | |\n"
                       "   | |---------------------| |\n"
                       "   | | OWNER:              | |\n"
                       "   | | BALANCE:            | |\n"
                       "   | |=========BLIK========| |\n"
                       "   | | CODE:               | |\n"
                       "   | |*********************| |\n"
                       "   | `---------------------' |\n"
                       "   |                         |\n"
                       "   |                         |\n"
                       "   ===========================";
    generateCode();
    for(int i=0;i<mobile.length();i++)
    {
        std::cout<<mobile[i];
        if(i==465)
        {
            std::cout<<owner<<std::right<<std::setw(14)<<accountOwner<<"| |\n";
            i+=30;
        }
        if(i==496)
        {
            std::cout<<balanceString<<std::right<<std::setw(10)<<balance<<"zl| |\n";
            i+=30;
        }
        if(i==558)
        {
            std::cout<<codeString<<std::right<<std::setw(15)<<code<<"| |\n";
            i+=30;
        }
    }

    std::cout<<std::endl;
}