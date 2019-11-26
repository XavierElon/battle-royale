//  This is the file for the derived Barbarian class.
//  barbarian.hpp
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.

#ifndef barbarian_hpp
#define barbarian_hpp

#include "character.hpp"
#include "dice.hpp"
#include <stdio.h>
#include <string>
using namespace std;


//  Derived class
class Barbarian : public Character
{
public:
    Barbarian();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    Dice defense2;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif /* barbarian_hpp */
