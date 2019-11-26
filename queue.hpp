//  This is the header file for the queue class.
//  Created by Xavier on 2/21/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include "character.hpp"
#include <stdio.h>

class Queue
{
    
public:
    Queue *tail;
    Queue *head;
    Queue *next;
    Queue *prev;
    Queue *temp;
    Character *opponent;
    
    //  Constructor and Deconstructor
    Queue();
    Queue(Character *);
    ~Queue();

    //  Member Functions
    bool isEmpty() const;
    void addBack(Character *);
    void addFront(Character *);
    Character* getFront();
    void removeFront();
    void moveToLastNode();
    void traverseList();
    
    
};

#endif /* queue_hpp */

