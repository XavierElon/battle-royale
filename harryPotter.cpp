
#include "harryPotter.hpp"
#include <iostream>
#include <string>
using namespace std;

//  Constructor to initialize character traits
HarryPotter::HarryPotter()
{
    type = "Harry Potter";
    strength = 10;
    armor = 0;
    lives = 2;
    alias = "";
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
    defense2 = Dice(6);
}


int HarryPotter::rollAttackDice()
{
        return Dice::rollTwo(attack1, attack2);
}

int HarryPotter::rollDefenseDice()
{
    return Dice::rollTwo(defense1, defense2);
}
