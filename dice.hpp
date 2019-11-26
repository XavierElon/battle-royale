//  This is the header file for the dice class.
//  Created by Xavier on 2/17/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef dice_hpp
#define dice_hpp

#include <stdio.h>

class Dice
{
protected:
    int numSides;
public:
    Dice();
    Dice(int numSides);
    int rollDie();
    static int rollOne(Dice &die1);
    static int rollTwo(Dice &die1, Dice &die2);
    static int rollThree(Dice &die1, Dice &die2, Dice &die3);
};

#endif /* dice_hpp */

