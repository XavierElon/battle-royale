//  This is the file for the derived Barbarian class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.


#include "barbarian.hpp"
#include <string>
using namespace std;

//  Constructor to initialize character traits
Barbarian::Barbarian()
{
    type = "Barbarian";
    strength = 12;
    armor = 0;
    lives = 1;
    alias = "";
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
    defense2 = Dice(6);
}



int Barbarian::rollAttackDice()
{
    return Dice::rollTwo(attack1, attack2);
}

int Barbarian::rollDefenseDice()
{
    return Dice::rollTwo(defense1, defense2);
}
