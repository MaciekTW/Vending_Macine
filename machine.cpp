//
// Created by Maciek on 16.11.2020.
//

#include "machine.h"

Maintenance maintenanceObj;
machine::machine() : serviceObj(0,amount,0,ARRAY_SIZE)
{
    srand( time( NULL ) );
    std::vector<int> temp_tab= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    setAmount( ARRAY_SIZE, temp_tab );
    setPage( 1 );
}

machine::machine( int size, std::vector<int> tab ) :serviceObj(0,tab,0,size)
{
    srand( time( NULL ) );
    setAmount( size, tab );
    setPage( 1 );
}

std::vector<int> machine::getAmount()
{
    return amount;
}

void machine::setAmount( int size, std::vector<int> &tab )
{
    for( int i = 0; i < size; i++ )
    {
        amount.push_back(tab[i]);
    }
}

std::string
machine::print( int &index, std::string id,
                std::string price )  //method helpful during printing non-ordinary elements of machine
{
    int i;
    if( id.length() == 1 && id != "-" )
        id = "0" + id;
    std::string priceReady = "";
    int counter1 = 0;

    for( int j = 0; j < price.length(); j++ )
    {
        if( price[ j ] == '.' )
        {
            priceReady += price[ j ];
            priceReady += price[ j + 1 ];
            priceReady += price[ j + 2 ];
            break;
        } else if( price[ j ] != '.' )
        {
            counter1++;
        }
        priceReady += price[ j ];
    }                                   //Described in file "temat2"
    if( counter1 == 1 )
    {
        priceReady.pop_back();
        priceReady.insert( 0, " " );
        priceReady.push_back( ' ' );
    }


    std::string temp = "";

    std::string str = "|####|`````````|####|"
                      "|####| |~~~~~| |####|"
                      "|####| |ORDER| |####|"
                      "|####| |~~~~~| |####|"
                      "|####| | #-- | |####|"
                      "|####| |~~~~~| |####|"
                      "|####|  1|2|3  |####|"
                      "|####|  4|5|6  |####|"
                      "|####|  7|8|9  |####|"
                      "|####|         |####|"
                      "|####|_________|####|";

    for( i = index; i < index + 21; i++ )
    {
        if( i == 50 && price != "ORDER" )
        {
            temp += priceReady;
            i += 4;
            continue;
        }
        if( i == 94 && id != "-" )
        {
            temp += id;
            i++;
            continue;
        }
        temp += str[ i ];
    }
    index = i;
    return temp;
}

void machine::print( std::vector<drink> stock, int size, std::string id, std::string price )
{
    std::cout << std::fixed;
    std::cout << "|================================VENDING MACHINE=================================|" << std::endl;
    std::cout << "|1. Acceptable coins: 10 gr 20 gr 50 gr 1 zl 2 zl 5 zl                           |" << std::endl;
    std::cout << "|2. Exact change only!                                                           |" << std::endl;
    std::cout << "|3. To exit order non-existing item                                              |" << std::endl;
    std::cout << "|4. To change page order <  or > to enter service mode order ?                   |" << std::endl;
    std::cout << "|5. High chance of winning the Christmas gift!                                   |" << std::endl;
    std::cout << "|________________________________________________________________________________|" << std::endl;
    std::cout << "|################################################################################|" << std::endl;
    int pos = 16 *
              ( page - 1 );                                                                    //described in temat2.txt
    int index = 0;
    for( int i = 0; i < MACHINE_SIZE; i++ )
    {
        std::string hash = ( i >= KEYPAD_START && i < KEYPAD_STOP ) ? print( index, id, price )
                                                                    : "|###################|";     //between keypad start and stop index overloaded print method would print non-ordinary elements of machine
        if( i % 5 == 0 )
        {
            std::cout << "|###|========================================================" << hash
                      << std::endl;
            continue;
        }
        if( pos < size )
        {
            std::cout << stock[ pos ] << "QTY: " << amount[ pos ] << "   " << hash << std::endl;;
            pos++;
        } else
        {
            std::cout << std::left << "|###| ID: " << std::setw( 3 ) << "-"
                      << "Product: " << std::setw( 16 ) << "*EMPTY SLOT*" << std::setprecision( 2 )
                      << "Price: " << std::setw( 7 ) << "-"
                      << "QTY: " << "-" << "   " << hash << std::endl;
        }
    }
    std::cout << "|###| NEXT PAGE: >  | PREVIOUS PAGE: <  |           PAGE: " << std::setw( 2 ) << page
              << " |###################|" << std::endl;


    std::string bottomElement = "|################################################################################|\n"
                                "|#####################################.(\\\\//). ##############|##``````````````###|\n"
                                "|####################################.(\\\\()//).##############|##     PUSH     ###|\n"
                                "|####################_##_########.----(\\)\\/(/)----.##########|##______________###|\n"
                                "|###################/_\\/_\\#######|     ///\\\\\\     |##############################|\n"
                                " \\          .=======\\_\\/_/=======.    ///||\\\\\\    |     ((\\o/))                 /\n"
                                "  |_________|       //  \\\\       |   //`||||`\\\\   |.-----//^\\\\-----.___________|\n"
                                "            |      //    \\\\      |      ||||      |     /`| |`\\    |\n"
                                "            |       |    |       |      ||||      |       | |      |\n"
                                "            |       |    |       |      ||||      |       | |      |\n"
                                "            '===================='------====------''------===------'\n";
    for( int i = 0; i < bottomElement.length(); i++ )
        std::cout << bottomElement[ i ];


}

bool machine::change( std::vector<drink>& stock, int size, int &pos )
{

    std::string x;
    std::cout << "Order by ID: ";
    std::cin >> x;
    if( x == "?" )
    {
        serviceObj.LogWrite<std::string, std::string, std::string, std::string>( "!!!SERVICE MODE ACTIVATED!!!" );
        serviceObj.serviceMenu(stock);
        maintenanceObj.clear();
        return true;
    }
    if( x == ">" )
    {
        pageUp();
        maintenanceObj.clear();
        print( stock, size );
        change( stock, size, pos);
        serviceObj.LogWrite<std::string, int, std::string, std::string>( "PAGE CHANGE: current page:", getPage() );
        return false;
    }
    if( x == "<" )
    {
        pageDown();
        maintenanceObj.clear();
        print( stock, size );
        change( stock, size, pos );
        serviceObj.LogWrite<std::string, int, std::string, std::string>( "PAGE CHANGE: current page:", getPage() );
        return false;
    }
    try
    {
        if( !findPos( std::stoi( x ), stock, pos, size ) )
        {
            serviceObj.LogWrite<std::string, std::string, std::string, std::string>(
                    "FAILED TRANSACTION: NON EXISTING ID:", x );
            throw WrongID();
        }
    }
    catch( const std::invalid_argument &arg )
    {
        maintenanceObj.bufforFix();
        change( stock, size, pos );
        return false;
    }

    if( !amount[ pos ] )
    {
        std::cout << "Out of stock!\n";
        serviceObj.LogWrite<std::string, std::string, std::string, std::string>( "FAILED TRANSACTION: [OUT OF STOCK]:",stock[ pos ].getName() );
        change( stock, size, pos );
        return false;
    }
    maintenanceObj.clear();
    print( stock, size, x, std::to_string( stock[ pos ].getPrice() ) );
    std::cout << "You've chosen " << stock[ pos ].getName() << std::endl;
    serviceObj.LogWrite<std::string, std::string, std::string, double>( "NEW ORDER: product name:",
                                                                        stock[ pos ].getName(), "price:",
                                                                        stock[ pos ].getPrice() );
    return false;
}

bool machine::pay( PaymentMethodContainer &payment, int choice, std::vector<drink> stock, int size, int pos )
{
    switch( choice )
    {
        case 1:
            maintenanceObj.clear();
            print( stock, size, std::to_string( pos ), std::to_string( payment.cash.getAmount() ) );
            return payment.MethodChoose(payment.cash);
            break;
        case 2:

            serviceObj.LogWrite<std::string, std::string, std::string, std::string>(
                    "ONLINE PAYMENT ATTEMPT: method: blik OWNER: ", payment.blik.getAccountOwver() );
            return payment.MethodChoose(payment.blik);
            break;
        case 3:
            serviceObj.LogWrite<std::string, std::string, std::string, std::string>(
                    "ONLINE PAYMENT ATTEMPT: method: credit cart cart number: ", payment.cart.getNumber() );
            return payment.MethodChoose(payment.cart);
            break;
    }
    return true;
}

bool machine::sold( double price, int pos, std::vector<drink> stock )
{
    if( price < PRECISION )
    {
        maintenanceObj.clear();
        amount[ pos ]--;
        serviceObj.serviceUpdate( stock[ pos ].getPrice(),amount );
        if( christmasGift( stock[ pos ].getName(), pos ) )
        {
            serviceObj.serviceUpdate( 0,amount );
            serviceObj.LogWrite<std::string, std::string, std::string, std::string>( "ITEM SOLD: x-mas gift:",
                                                                                stock[ pos ].getName(), "price: 0");
        }
        std::cout << "Item sold!" << std::endl;
        serviceObj.LogWrite<std::string, std::string, std::string, double>( "ITEM SOLD: name:", stock[ pos ].getName(),
                                                                            "price:", stock[ pos ].getPrice() );
        return true;
    }

    return false;
}

bool machine::christmasGift( std::string name, int pos )
{
    if( rand() / ( RAND_MAX + 1.0 ) < 0.4 && amount[ pos ] > 0 )
    {
        std::cout << "You have won a free extra bottle of " << name << " Merry X-mas!\n";
        amount[ pos ]--;
        return true;
    } else
        return false;
}

bool machine::findPos( int x, std::vector<drink> stock, int &pos,
                       int size )        //x is an id of a product, method looks for index of product with such id in an array
{
    for( int i = 0; i < size; i++ )
        if( x == stock[ i ].getID() )
        {
            pos = i;
            return true;
        }
    return false;
}

machine::~machine()
{
    //delete[] amount;
}

bool machine::stop()
{

    std::cout << "Reorder? [y/n]: ";
    char x;
    std::cin >> x;
    if( x == 'y' || x == 'Y' )
    {
        maintenanceObj.clear();
        return true;
    } else if( x == 'n' || x == 'N' )
    {
        maintenanceObj.ChristmasBox();
        std::cout << "See you soon :)" << std::endl;
        return false;
    }
    return stop();
}

void machine::setPage( int page )
{
    this->page = page;
}

int machine::getPage()
{
    return page;
}

void machine::setPrice( PaymentMethodContainer &payment, float price, int method )
{
    if( price < 0 )
        throw WrongPrice();

    switch( method )
    {
        case 1:
            payment.cash.setAmount( price );
            break;
        case 2:
            payment.blik.setAmount( price );
            break;
        case 3:
            payment.cart.setAmount( price );
            break;
    }
}




