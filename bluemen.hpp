//  This is the header file for the derived BlueMen class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef blueMen_hpp
#define blueMen_hpp

#include <stdio.h>
#include <string>
#include "character.hpp"
#include "dice.hpp"
using namespace std;


//  Derived class
class BlueMen : public Character
{
public:
    BlueMen();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    Dice defense2;
    Dice defense3;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif /* blueMen_hpp */
