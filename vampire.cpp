//  This is the file for the derived Vampire class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "vampire.hpp"
#include <iostream>
#include <string>
using namespace std;

//  Constructor to initialize character traits
Vampire::Vampire()
{
    type = "Vampire";
    strength = 18;
    armor = 1;
    lives = 1;
    alias = "";
    attack1 = Dice(12);
    defense1 = Dice(6);
}


int Vampire::rollAttackDice()
{
    return Dice::rollOne(attack1);
}

int Vampire::rollDefenseDice()
{
    if (fiftyFifty())
    {
        cout << "The vampire used charm and will not receive any damage." << endl;
        return 100;
    }
    return Dice::rollOne(defense1);
}

bool Vampire::fiftyFifty()
{
    
    int fifty = (rand() % 2);
    if (fifty == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
