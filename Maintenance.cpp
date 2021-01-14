//
// Created by Maciek on 18.12.2020.
//

#include "Maintenance.h"

void Maintenance::clear(int n)
{
    for( int i = 0; i < n; i++ )
        std::cout << "\n";
}

void Maintenance::bufforFix()
{
    std::cin.clear();
    std::cin.ignore( 10000, '\n' );
    fflush( stdin );
}
void Maintenance::ErrorBox(){
    clear();
    std::string error=" __    __     ______  __    __     \n"
                      "|  |  |  |   /  __  \\|  |  |  |   \n"
                      "|  |__|  |__|  |  |  |  |__|  |__\n"
                      "|_____    __|  |  |  |_____    __\n"
                      "      |  |  |  |  |  |     |  |  \n"
                      "      |  |  |  |__|  |     |  |  \n"
                      "      |__|   \\______/      |__|  \n"
                      "        PAYMENT NOT FOUND!\n";
    for(int i=0;i<error.length();i++)
        std::cout<<error[i];
    clear(10);
    std::cout<<"Upsi gupsi, payment process went wrong :(( Try again later!"<<std::endl;
}
void Maintenance::ChristmasBox()
{

    std::string text=
   "          A\n"
   "          /$\\               /\\  /\\    ___  _ __  _ __ __    __\n"
   "         / * \\             /  \\/  \\  / _ \\| '__|| '__|\\ \\  / /\n"
   "        /$$$$$\\           / /\\  /\\ \\|  __/| |   | |    \\ \\/ /\n"
   "        /  O  \\          / /  \\/  \\ \\\\___/|_|   |_|     \\  /\n"
   "       / * * o \\                                        / /\n"
   "      /$$$$$$$$$\\        __  __                        /_/    _\n"
   "      /  *   *  \\        \\ \\/ /        /\\  /\\    __ _  ____  | |\n"
   "     / o   O   o \\        \\  /   __   /  \\/  \\  / _` |/ ___\\ |_|\n"
   "    /$$$$$$$$$$$$$\\       /  \\  |__| / /\\  /\\ \\| (_| |\\___ \\  _\n"
   "    /  o   *   O  \\      /_/\\_\\      \\ \\ \\/ / / \\__,_|\\____/ |_|\n"
   "   / *   O   o   * \\\n"
   "  /$$$$$$$$$$$$$$$$$\\\n"
   "         |___|";                                                                //Author: ASCIIart.eu

    for(int i=0;i<text.length();i++)
        std::cout<<text[i];

}