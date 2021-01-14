#include <iostream>
#include <cstdio>
#include <vector>
#include "drink.h"
#include "machine.h"
#include "Maintenance.h"
#include "Blik.h"
#include "Cash.h"
#include "Karta.h"

#include "PaymentMethodContainer.h"


int main( int argc, char *argv[] )
{
    if(argc == 2)
    {
        freopen(argv[1],"r",stdin);
    }


    Maintenance maintenance;
    double price;
    drink soda( 0, "Coke", 2 );
    drink juice( 1, "juice", 3.7 );
    drink water_s( 20, "Still water", 6.1 );
    drink water( 21, "Sparkling water", 10 );
    drink tea( 23, "Ice Tea", 14 );
    drink Fanta( 24, "Fanta", 5.20 );
    drink Sprite( 25, "Sprite", 3.50 );
    drink Pepsi( 26, "Pepsi", 14 );
    drink TigerG( 40, "Tiger GOLD", 50.20 );
    drink Tiger( 41, "Tiger", 5.80 );
    drink MonsterR( 42, "Monster Red", 6.40 );
    drink MonsterG( 43, "Monster Green", 6.40 );
    drink MonsterY( 44, "Monster Yellow", 6.40 );
    drink MonsterW( 45, "Monster White", 6.40 );
    drink MonsterB( 46, "Monster Black", 6.40 );
    drink MonsterGL( 47, "Monster Gold", 7.60 );
    drink HotChocolate( 60, "Hot Chocolate", 4.50 );
    drink ColdChocolate( 61, "Cold Chocolate", 2.50 );
    Karta cart( "11 11111111111", 234, 122.45, 1234 );
    Cash cash( "Dan" );
    Blik blik( "Maciek", 100.34 );

    PaymentMethodContainer payment( cash,blik,cart );

    std::vector<drink> stock={ soda, juice, water_s, water, tea, Fanta, Sprite, Pepsi, TigerG, Tiger, MonsterR,
                             MonsterG, MonsterY, MonsterW, MonsterB, MonsterGL, HotChocolate, ColdChocolate };

    machine Machine;
    int pos;
    int method;
    do
    {
        Machine.print( stock, stock.size() );
        try
        {
            if(Machine.change( stock, stock.size(), pos ))
                continue;
            price = stock[ pos ].getPrice();
            method = payment.printMethods();
            maintenance.clear();
            Machine.setPrice( payment, price, method );
        }catch(WrongID & arg){
            std::cout << arg.what();
            exit( INDEX_ERROR );
        }catch( WrongPrice & arg)
        {
            std::cout << arg.what();
            exit( PRICE_ERROR );
        }
        while( !Machine.sold( payment.getAmount( method ), pos, stock ) )
            if( !Machine.pay( payment, method, stock, stock.size(), pos ) )
            {
                maintenance.ErrorBox();
                break;
            }
    } while( Machine.stop() );

    return 0;
}
