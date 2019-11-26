//  This is the file for the derived BlueMen class.
//  blueMen.cpp
//  project3
//
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <iostream>
#include <string>
#include "bluemen.hpp"
using namespace std;

//  Constructor to initialize character traits
BlueMen::BlueMen()
{
    type = "BlueMen";
    strength = 12;
    armor = 3;
    lives = 1;
    alias = "";
    attack1 = Dice(10);
    attack2 = Dice(10);
    defense1 = Dice(6);
    defense2 = Dice(6);
    defense3 = Dice(6);
}


int BlueMen::rollAttackDice()
{
    return Dice::rollTwo(attack1, attack2);
}


int BlueMen::rollDefenseDice()
{
    if (*mobDamage >= 12)
    {
        return 0;
    }
    else if (*mobDamage >= 8)
    {
        return Dice::rollOne(defense1);
    }
    else if (*mobDamage >= 4)
    {
        return Dice::rollTwo(defense1, defense2);
    }
    else
    {
        return Dice::rollThree(defense1, defense2, defense3);
    }
}
