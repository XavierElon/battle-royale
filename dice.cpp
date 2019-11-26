//  This is the file for the Dice classs which holds the function to roll the dice or die.
//  Created by Xavier on 2/17/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "dice.hpp"
#include <cmath>
#include <ctime>
#include <stdlib.h>

//  Constructor
Dice::Dice()
{
    numSides = 6;
    //  Seed random number generator
    unsigned seed;
    seed = time(0);
    srand(seed);
}

//  Constructor with numSides as parameter
Dice::Dice(int numSides)
{
    this -> numSides = numSides;
    //  Seed random number generator
    unsigned seed;
    seed = time(0);
    srand(seed);
}

/*****************************************************
 ** Function: rollDie
 ** Description: This function rolls one die using the random seed and returns the result
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Returns result of random die roll
 *******************************************************/
int Dice::rollDie()
{
    return (rand() % numSides) + 1;
}

/*****************************************************
 ** Function: rollOne
 ** Description: This function rolls one die using the random seed and returns the result
 ** Parameters: Dice object as address
 ** Pre-Conditions: None
 ** Post-Conditions: Returns result of single random die roll
 *******************************************************/
int Dice::rollOne(Dice &die1)
{
    return die1.rollDie();
}

/*****************************************************
 ** Function: rollTwo
 ** Description: This function will rolls two dice and return the sum.
 ** Parameters: Takes two dice objects as addresses
 ** Pre-Conditions: None
 ** Post-Conditions:returns sum of two dice rolls
 *******************************************************/
int Dice::rollTwo(Dice &die1, Dice &die2)
{
    return die1.rollDie() + die2.rollDie();
}

/*****************************************************
 ** Function: rollThree
 ** Description: This function will roll three dice and return the sum.
 ** Parameters: Three dice object addresses
 ** Pre-Conditions: N/A
 ** Post-Conditions: Returns the sum of three randomly rolled dice.
 *******************************************************/
int Dice::rollThree(Dice &die1, Dice &die2, Dice &die3)
{
    return die1.rollDie() + die2.rollDie() + die3.rollDie();
}
