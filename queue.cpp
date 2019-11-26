//  This is the file for the queue class.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "queue.hpp"
#include "character.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;



//  Constructor
Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
}


Queue::Queue(Character *fighter)
{
    opponent = fighter;
    next = nullptr;
}


//  Deconstructor
Queue::~Queue()
{
    Queue *garbage;
    if(isEmpty())
    {
        return;
    }
    while (head != nullptr)
    {
        garbage = tail -> prev;
        tail -> prev = head -> next;
        delete garbage;
    }
}


//  Checks if the queue is empty
bool Queue::isEmpty() const
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//  Adds a user entered value to the tail of the queue
void Queue::addBack(Character *fighter)
{
    
    Queue *temp = new Queue(fighter);
    
    temp -> opponent = fighter;
    if (isEmpty())
    {
        tail = head = temp;
    }
    //  Adjusts all pointers in the queue if there is more than one value in the queue
    else
    {
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void Queue::addFront(Character *fighter)
{
    Queue *temp = new Queue(fighter);
    
    temp -> opponent = fighter;
    if(tail == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

//  Displays the front value of the queue
Character* Queue::getFront()
{
    if (isEmpty())
    {
        return nullptr;
    }
    else
    {
        return opponent;
    }
}


//  Removes the front value of the queue
void Queue::removeFront()
{
    Queue *temp = head;
    
    if (isEmpty())
    {
        cout << endl << "The queue is currently empty." << endl;
    }
    
    //  If there is only one value in the queue
    else if (head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    
    //  If there is more than one value in the queue
    else
    {
        head = head -> next;
        head -> prev = temp -> prev;
        head -> prev -> next = head;
        delete temp;
    }
}

 

void Queue::moveToLastNode()
{
    if (head == tail)
    {
        return;
    }
    Queue *ptr = head;
    head = ptr -> next;
    ptr -> next = nullptr;
    
    tail -> next = ptr;
    tail = ptr;
}

void Queue::traverseList()
{
    Queue *ptr = head;
    cout << "The current node list is: ";
    if (ptr == nullptr)
    {
        cout << "The node list is empty. " << endl;
        return;
    }
    while (ptr != nullptr)
    {
        cout << ptr -> opponent << " ";
        ptr = ptr -> next;
    }
    cout << endl << endl;
}


