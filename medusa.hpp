//  This is the header file for the derived Medusa class
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef medusa_hpp
#define medusa_hpp

#include <stdio.h>
#include <string>
#include "dice.hpp"
#include "character.hpp"
using namespace std;


//  Derived class
class Medusa : public Character
{
public:
    Medusa();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif /* medusa_hpp */
