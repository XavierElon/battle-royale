/***********************************************************************
 ** Program name: Fantasy Game
 ** Author: Xaiver Hollingsworth
 ** Date: 02/10/2018
 ** Description: This is  fantasy game where the user gets to select two
 ** characters. The characters then battle by rolling die until one dies.
 **
 ***********************************************************************/

#include <unistd.h>
#include <iostream>
#include <ctime>
#include "functions.hpp"
using namespace std;





//  MAIN
int main() {
    titleDisplay();
    do{
        playMenu();
    }while(playAgain());
    
    
    return 0;
}
