//  This is the header file for the functions file.
//  Created by Xavier on 2/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include "character.hpp"
#include "queue.hpp"

void titleDisplay();
void playMenu();
void retrieveNumbers();
void retrieveTeams(int, int);
void createTeam1(int [], int, Queue *);
void createTeam2(int [], int, Queue *);
bool playAgain();
void runGame(int, int);
void fightMain(Queue *, Queue*);

#endif /* functions_hpp */
