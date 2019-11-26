//  This is the file that contains various functions like the menu, rolling the die, and
//  Created by Xavier on 2/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include "functions.hpp"
#include "queue.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
using namespace std;


void titleDisplay()
{
    cout << "*** Welcome to the Fantasy Combat Game *** " << endl;
}


void fightMain(Queue *team1, Queue *team2)
{
    Queue winners, losers;
    Character *player1 = team1->getFront();
    Character *player2 = team2->getFront();
    bool gameOver = false;
    cout << endl << "*******************************************" << endl;
    cout << player1 -> getType() << " Versus " << player2 -> getType() << endl;
    cout << endl << "*******************************************" << endl << endl;
    cout << player1 -> getName() << " starting strength: " << player1 -> getStrength() << endl;
    cout << player2 -> getName() << " starting strength: " << player2 -> getStrength() << endl;
    usleep(1000000);
    while (!gameOver)
    {
        player1 -> attack(player2);
        player2 -> attack(player1);
        
        cout << endl << player1 -> getType() << " remaining strength: " << player1 -> getStrength();
        cout << endl << player2 -> getType() << " remaining strength: " << player2 -> getStrength();
        cout << endl;
        
        if (player1 -> isDead())
        {
            cout << endl << player1 -> getType() << " is dead!" << endl;
            gameOver = true;
            team1->removeFront();
            team2->moveToLastNode();
            losers.addBack(player1);
        }
        if (player2 -> isDead())
        {
            cout << endl << player2 -> getType() << " is dead! Game Over!" << endl;
            gameOver = true;
            team2->removeFront();
            team1->moveToLastNode();
        }
    }
    cout << endl;
}







void playMenu()
{
    int choice;
    
    cout << "***Please select an option below***" << endl;
    cout << "1: Play" << endl;
    cout << "2: Exit" << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2)   {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid." << endl;
        playMenu();
    }
    if (choice == 1)
    {
        retrieveNumbers();
    }
    else
    {
        cout << "Thanks for playing!" << endl << endl;
        usleep(1000000);
        exit(0);
    }
}


void retrieveNumbers()
{
    int team1, team2;

    
    cout << "Enter the number of fighters for Team 1: ";
    cin >> team1;
    while (team1 < 1 || team1 > 10)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection invalid. Please enter between 1 and 10 for the number of fighters on Team 1: ";
        cin >> team1;
    }
    cout << "Enter the number of fighters for Team 2: ";
    cin >> team2;
    while (team2 < 1 || team2 > 10)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection invalid. Please enter between 1 and 10 for the number of fighters on Team 2: ";
        cin >> team2;
    }
    retrieveTeams(team1, team2);
}

void retrieveTeams(int team1, int team2)
{
    
    int fighter[team1];
    int *ptr = fighter;
    int fighter2[team2];
    int *ptr2 = fighter2;
    Queue q1, q2;
    Queue *teamOne = &q1;
    Queue *teamTwo = &q2;
    
    
    for (int i = 0; i < team1; i++)
    {
        cout << "Select the number for the fighter you would like to use for poisition " << i << " on Team 1." << endl;
        cout << "1: Vampire" << endl;
        cout << "2: Barbarian" << endl;
        cout << "3: Blue Men" << endl;
        cout << "4: Medusa" << endl;
        cout << "5: Harry Potter" << endl;
        cout << "Enter a choice: ";
        cin >> fighter[i];
        while (fighter[i] < 1 || fighter[i] > 5)
        {
            cin.clear();
            cin.ignore();
            cout << "Selection invalid. Please enter between 1 and 5 for the fighter you would like at position " << (i + 1) << " on Team 1: " ;
            cin >> fighter[i];
        }
        cin.clear();
        cin.ignore();
        createTeam1(ptr, team1, teamOne);
    }
    
    for (int j = 0; j < team2; j++)
    {
        cout << "Select the number for the fighter you would like to use for poisition " << j << " on Team 2." << endl;
        cout << "1: Vampire" << endl;
        cout << "2: Barbarian" << endl;
        cout << "3: Blue Men" << endl;
        cout << "4: Medusa" << endl;
        cout << "5: Harry Potter" << endl;
        cout << "Enter a choice: ";
        cin >> fighter2[j];
        while (fighter2[j] < 1 || fighter2[j] > 5)
        {
            cin.clear();
            cin.ignore();
            cout << "Selection invalid. Please enter between 1 and 5 for the fighter you would like at position " << (j + 1) << " on Team 2: " ;
            cin >> fighter2[j];
        }
    }
    cin.clear();
    cin.ignore();
    createTeam2(ptr2, team2, teamTwo);
    while (!q1.isEmpty() && !q2.isEmpty())
    {
        
        fightMain(teamOne, teamTwo);
    }
    
}

void createTeam1(int fighter[], int number, Queue *q1)
{
    for (int i = 0; i <= number; i++)
    {
        if (fighter[i] == 1)
        {
            Character *fighter = new Vampire();
            fighter->setName(i+1);
            q1 -> addBack(fighter);

        }
        else if (fighter[i] == 2)
        {
            Character *fighter = new Barbarian();
            fighter->setName(i+1);
            q1 ->addBack(fighter);
        }
        else if (*fighter == 3)
        {
            Character *fighter = new BlueMen();
            fighter->setName(i+1);
            q1 -> addBack(fighter);
        }
        else if (*fighter == 4)
        {
            Character *fighter = new Medusa();
            fighter->setName(i+1);
            q1 -> addBack(fighter);
        }
        else if (*fighter == 5)
        {
            Character *fighter = new HarryPotter();
            fighter->setName(i+1);
            q1 -> addBack(fighter);
        }
    }
}

void createTeam2(int fighter2[], int number2, Queue *q2)
{
    for (int i = 0; i <= number2; i++)
    {
        if (fighter2[i] == 1)
        {
            Character *fighter2 = new Vampire();
            fighter2->setName(i+1);
            q2->addBack(fighter2);
            
        }
        else if (fighter2[i] == 2)
        {
            Character *fighter2 = new Barbarian();
            fighter2->setName(i+1);
            q2->addBack(fighter2);
        }
        else if (*fighter2 == 3)
        {
            Character *fighter2 = new BlueMen();
            fighter2->setName(i+1);
            q2->addBack(fighter2);
        }
        else if (*fighter2 == 4)
        {
            Character *fighter2 = new Medusa();
            fighter2->setName(i+1);
            q2->addBack(fighter2);
        }
        else if (*fighter2 == 5)
        {
            Character *fighter2 = new HarryPotter();
            fighter2->setName(i+1);
            q2->addBack(fighter2);
        }
    }
}


//  Function to give player an option to run the game again
bool playAgain()
{
    int choice;
    bool again = false;
    
    cout << "***Please select an option below***" << endl;
    cout << "1: Play game again." << endl;
    cout << "2: Quit game." << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: " << endl;
        cin >> choice;
    }
    if (choice == 1)
    {
        again = true;
        return again;
    }
    else
    {
        cout << "Thanks for playing!" << endl << endl;
        usleep(1000000);
        return again = false;
    }
}



/*******************************************************************************************
 ** Function: runGame
 ** Description: This function runs the game.
 ** Parameters: Character1, and character2
 ** Pre-Conditions: None
 ** Post-Conditions: Displays results of game
 *******************************************************************************************/

//void runGame(int character1, int character2)
//{
//    if (character1 == 1 && character2 == 1)
//    {
//        fightMain(new Vampire, new Vampire);
//    }
//    else if (character1 == 1 && character2 == 2)
//    {
//        fightMain(new Vampire, new Barbarian);
//    }
//    else if (character1 == 1 && character2 == 3)
//    {
//        fightMain(new Vampire, new BlueMen);
//    }
//    else if (character1 == 1 && character2 == 4)
//    {
//        fightMain(new Vampire, new Barbarian);
//    }
//    else if (character1 == 1 && character2 == 5)
//    {
//        fightMain(new Vampire, new HarryPotter);
//    }
//    else if (character1 == 2 && character2 == 1)
//    {
//        fightMain(new Barbarian, new Vampire);
//    }
//    else if (character1 == 2 && character2 == 2)
//    {
//        fightMain(new Barbarian, new Barbarian);
//    }
//    else if (character1 == 2 && character2 == 3)
//    {
//        fightMain(new Barbarian, new BlueMen);
//    }
//    else if (character1 == 2 && character2 == 4)
//    {
//        fightMain(new Barbarian, new Medusa);
//    }
//    else if (character1 == 2 && character2 == 5)
//    {
//        fightMain(new Barbarian, new HarryPotter);
//    }
//    else if (character1 == 3 && character2 == 1)
//    {
//        fightMain(new BlueMen, new Vampire);
//    }
//    else if (character1 == 3 && character2 == 2)
//    {
//        fightMain(new BlueMen, new Barbarian);
//    }
//    else if (character1 == 3 && character2 == 3)
//    {
//        fightMain(new BlueMen, new BlueMen);
//    }
//    else if (character1 == 3 && character2 == 4)
//    {
//        fightMain(new BlueMen, new Medusa);
//    }
//    else if (character1 == 3 && character2 == 5)
//    {
//        fightMain(new BlueMen, new HarryPotter);
//    }
//    else if (character1 == 4 && character2 == 1)
//    {
//        fightMain(new Medusa, new Vampire);
//    }
//    else if (character1 == 4 && character2 == 2)
//    {
//        fightMain(new Medusa, new Barbarian);
//    }
//    else if (character1 == 4 && character2 == 3)
//    {
//        fightMain(new Medusa, new BlueMen);
//    }
//    else if (character1 == 4 && character2 == 4)
//    {
//        fightMain(new Medusa, new Medusa);
//    }
//    else if (character1 == 4 && character2 == 5)
//    {
//        fightMain(new Medusa, new HarryPotter);
//    }
//    else if (character1 == 5 && character2 == 1)
//    {
//        fightMain(new HarryPotter, new Vampire);
//    }
//    else if (character1 == 5 && character2 == 2)
//    {
//        fightMain(new HarryPotter, new Barbarian);
//    }
//    else if (character1 == 5 && character2 == 3)
//    {
//        fightMain(new HarryPotter, new BlueMen);
//    }
//    else if (character1 == 5 && character2 == 4)
//    {
//        fightMain(new HarryPotter, new Medusa);
//    }
//    else if (character1 == 5 && character2 == 5)
//    {
//        fightMain(new HarryPotter, new HarryPotter);
//    }
//}
