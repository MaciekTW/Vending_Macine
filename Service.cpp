//
// Created by Maciek on 06.01.2021.
//

#include "Service.h"


Maintenance MaintenanceObject;

Service::Service()
{
    stock = temp;
    balance = 0;
    soldAmount = 0;
    uniqueDrinks = 0;
}

Service::Service( double balance, std::vector<int> &stock, int soldAmount, int drinks ) : stock( stock )
{
    this->balance = balance;
    this->soldAmount = soldAmount;
    uniqueDrinks = drinks;
}

void Service::printSummary()
{
    MaintenanceObject.clear();
    std::cout << "========================MACHINE STATS========================" << std::endl;
    std::cout << "Total income:" << balance << std::endl;
    std::cout << "Drinks sold:" << soldAmount << std::endl;
    std::cout << "Available " << drinksLeft() << " out of " << uniqueDrinks << " drink" << std::endl;
    std::cout << "Bottles left: " << bottlesLeft() << std::endl;
    std::cout << "=============================================================" << std::endl;
    MaintenanceObject.clear( 10 );
    stop();
}

double Service::getBalance()
{
    return balance;
}

void Service::setBalance( double saldo )
{
    balance = saldo;
}

std::vector<int> Service::getAmount()
{
    return stock;
}

void Service::setAmount( std::vector<int> &saldo )
{
    stock = saldo;
}

void Service::increaseBalance( double sum )
{
    if( sum < 0 )
        throw std::invalid_argument( "Wrong Price!" );

    setBalance( balance + sum );
}

void Service::increaseSoldAmount()
{
    soldAmount++;
}

void Service::serviceUpdate( double price, std::vector<int> &temp )
{
    try
    {
        increaseBalance( price );
        increaseSoldAmount();
    }
    catch( std::invalid_argument &arg )
    {
        std::cout << "Blad" << std::endl;
    }
}

int Service::drinksLeft()
{
    int drinkCounter = uniqueDrinks;
    for( int i = 0; i < uniqueDrinks; i++ )
    {
        if( stock[ i ] == 0 )
            drinkCounter--;
    }
    return drinkCounter;
}

int Service::bottlesLeft()
{
    int drinkCounter = 0;
    for( int i = 0; i < uniqueDrinks; i++ )
    {
        drinkCounter += stock[ i ];
    }
    return drinkCounter;
}

void Service::fileOpen( std::string fileName )
{
    logFile.open( fileName, std::ios::app | std::ios::in );
    if( !logFile.good() )
    {
        throw FileError();
    }
}

void Service::serviceMenu( std::vector<drink> &drinkTab )
{
    MaintenanceObject.clear();
    std::cout << "+++++++++++++++++++++SERVICE MODE+++++++++++++++++++++" << std::endl;
    std::cout << "*              1. Show summary report                *" << std::endl;
    std::cout << "*              2. Show logs                          *" << std::endl;
    std::cout << "*              3. Change a price                     *" << std::endl;
    std::cout << "*              4. Add a drink                        *" << std::endl;
    std::cout << "*              5. Refill the machine                 *" << std::endl;
    std::cout << "*              6. Exit service mode                  *" << std::endl;
    std::cout << "*++++++++++++++++++++++++++++++++++++++++++++++++++++*" << std::endl;
    MaintenanceObject.clear( 15 );

    std::cout << "Choice: ";
    int temp;
    if( !( std::cin >> temp ) )
    {
        std::cout << "Invalid argument!" << std::endl;
        MaintenanceObject.bufforFix();
        serviceMenu( drinkTab );
    }

    switch( temp )
    {
        case 1:
            printSummary();
            break;
        case 2:
            showLogs();
            break;
        case 4:
            try
            {
                addItem( drinkTab );;
            } catch( WrongID &arg )
            {
                std::cout << arg.what();
                LogWrite<std::string, std::string, std::string, std::string>( "PRICE CHANGE ERROR: ID error" );
                MaintenanceObject.bufforFix();
                return;
            } catch( WrongPrice &arg )
            {
                std::cout << arg.what();
                LogWrite<std::string, std::string, std::string, std::string>( "PRICE CHANGE ERROR: price error" );
                MaintenanceObject.bufforFix();
                return;
            }
            catch( WrongName &arg )
            {
                std::cout << arg.what();
                LogWrite<std::string, std::string, std::string, std::string>( "PRICE CHANGE ERROR: name error" );
                MaintenanceObject.bufforFix();
                return;
            }
            break;
        case 3:
            try
            {
                priceChange( drinkTab );
            } catch( WrongID &arg )
            {
                std::cout << arg.what();
                LogWrite<std::string, std::string, std::string, std::string>( "PRICE CHANGE ERROR: ID error" );
                MaintenanceObject.bufforFix();
                return;
            } catch( WrongPrice &arg )
            {
                std::cout << arg.what();
                LogWrite<std::string, std::string, std::string, std::string>( "PRICE CHANGE ERROR: price error" );
                MaintenanceObject.bufforFix();
                return;
            }
            break;
        case 5:
            machineRefillMenu( drinkTab );
            break;
        case 6:
            LogWrite<std::string, std::string, std::string, std::string>( "!!!SERVICE MODE SESSION ENDED!!!" );
            return;
            break;
        default:
            std::cout << "No such choice" << std::endl;
    }
    serviceMenu( drinkTab );

}

void Service::showLogs()
{
    MaintenanceObject.clear();
    std::string text;
    std::cout << "=====================LOG FILE=====================" << std::endl;
    LogWrite<std::string, std::string, std::string, std::string>( "SERVICE MODE: log access granted" );
    fileOpen( "LogFile.txt" );
    while( !logFile.eof() )
    {
        getline( logFile, text );
        std::cout << text << std::endl;
    }
    logFile.close();
    stop();
}

bool Service::stop()
{
    std::string c;

    do
    {
        std::cout << "To continue type y: ";
        if( !( std::cin >> c ) )
            MaintenanceObject.bufforFix();
    } while( c != "Y" && c != "y" );

    return true;

}

void Service::machineRefillMenu( std::vector<drink> drinkTab )
{
    bool empty = true;
    std::vector<int> vec;
    MaintenanceObject.clear();
    int pos = 1;
    std::cout << "**********************To Refil**********************" << std::endl;
    for( int i = 0; i < uniqueDrinks; i++ )
    {
        if( stock[ i ] != 3 )
        {
            empty = false;
            std::cout << "  " << pos++ << ". NAME: " << std::setw( 20 ) << drinkTab[ i ].getName() << std::setw( 2 )
                      << stock[ i ] << " out of 3" << std::endl;
            vec.push_back( i );
        }
    }
    if( empty )
    {
        std::cout << "There is nothing to refill!" << std::endl;
        std::cout << "****************************************************" << std::endl;
        stop();
        return;
    }
    std::cout << "****************************************************" << std::endl;
    std::string x;
    MaintenanceObject.clear( 10 );
    std::cout << "1.To refill all drinks type ALL" << std::endl;
    std::cout << "Chose drink to refill by number"
                 ": ";
    if( !( std::cin >> x ) )
        std::cout << "ERROR " << std::endl;

    if( x == "ALL" || x == "all" )
    {
        refill( pos, vec );
        stop();
        return;
    }
    try
    {

        if( std::stoi( x ) > vec.size() )
        {
            LogWrite<std::string, std::string, std::string, std::string>( "REFILL FAILED: non existing ID:", x );
            throw WrongID();
        }

        refill( vec[ std::stoi( x ) - 1 ], drinkTab[ vec[ std::stoi( x ) - 1 ] ].getName() );
    } catch( const std::invalid_argument &arg )
    {
        stop();
        return;
    }
    MaintenanceObject.clear( 10 );
    stop();
}

void Service::refill( int pos, std::string name )
{
    stock[ pos ] = 3;
    LogWrite<std::string, std::string, std::string, std::string>( "REFILL SUCCESS:", name, "resupplied" );
    std::cout << name << " resupplied";
}

void Service::refill( int pos, std::vector<int> ids )
{
    for( int i = 0; i < ids.size(); i++ )
        stock[ ids[ i ] ] = 3;

    LogWrite<std::string, std::string, std::string, std::string>( "REFILL SUCCESS:", "All drinks resupplied" );
    std::cout << "All drinks resupplied\n";
}

void Service::addItem( std::vector<drink> &drinks )
{
    std::string name;
    int id;
    double price;
    MaintenanceObject.clear( 50 );
    std::cout << "********************DRINK ADDING********************" << std::endl;
    std::cout << "Drink ID: ";
    if( !( std::cin >> id ) )
        throw WrongID();
    if( checkID( drinks, id ) )
    {
        std::cout << "THIS ID IS ALREADY USED !" << std::endl;
        stop();
        return;
    }
    std::cout << "Input a price: ";
    if( !( std::cin >> price ) || price < 0 )
        throw WrongPrice();
    std::cout << "Input a drink name: ";
    if( !( std::cin >> name ) || name.size() > 15 )
        throw WrongName();


    drink newDrink( id, name, price );
    drinks.push_back( newDrink );
    stock.push_back( 3 );
    uniqueDrinks += 1;
    LogWrite<std::string, std::string, std::string, std::string>( "ITEM ADDED:", drinks[ drinks.size() - 1 ].getName(),
                                                                  "is now available" );
    std::cout << "Drink " << drinks[ drinks.size() - 1 ].getName() << " has beed added" << std::endl;
    stop();
}

void Service::priceChange( std::vector<drink> &drinks )
{
    int id;
    double price;
    std::cout << "***********************DRINK LIST***********************" << std::endl;
    for( int i = 0; i < drinks.size(); i++ )
        std::cout << "      " << std::setw( 2 ) << i << ". " << std::setw( 20 ) << drinks[ i ].getName()
                  << "current price: " << std::setw( 2 ) << drinks[ i ].getPrice() << " zl" << std::endl;

    std::cout << "Drink by number: ";
    if( !( std::cin >> id ) || id > ( drinks.size() - 1 ) )
        throw WrongID();

    std::cout << "Input a new price: ";
    if( !( std::cin >> price ) || price < 0 )
        throw WrongPrice();


    drinks[ id ].setPrice( price );

    LogWrite<std::string, std::string, std::string, double>( "PRICE CHANGE:", drinks[ id ].getName(), "costs now ",
                                                             drinks[ id ].getPrice() );
    std::cout << "Price changed for " << drinks[ id ].getName() << std::endl;
    stop();
}

bool Service::checkID( std::vector<drink> &drinks, int id )
{
    for( int i = 0; i < drinks.size(); i++ )
        if( drinks[ i ].getID() == id )
            return true;

    return false;
}



