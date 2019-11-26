//  This is the header file for the derived HarryPotter class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef harryPotter_hpp
#define harryPotter_hpp

#include <stdio.h>
#include <string>
#include "character.hpp"
#include "dice.hpp"


//  Derived class
class HarryPotter : public Character
{
public:
    HarryPotter();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    Dice defense2;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif /* harryPotter_hpp */
