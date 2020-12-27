#ifndef _priorityQueueInt_h
#define _priorityQueueInt_h
#include <stdlib.h>
#include <stdbool.h>



typedef struct pqType
{
    int priority;           //priority of this element
    int info;           //Change this line to set the type for the priority queue to store
} pqType;

typedef struct PriorityQueue
{
    pqType *data;        //pqType data stored in the stack
    int last;                //index of the last element in the array
    int capacity;           //current capacity of stack
} PriorityQueue;

PriorityQueue *createPQ( );
void freePQ( PriorityQueue *ppq );
//void freePQElements( PriorityQueue *ps  );

pqType removePQ( PriorityQueue *ppq );
void insertPQ( PriorityQueue *ppq, pqType pt );
pqType getNextPQ( PriorityQueue *ppq );

bool isEmptyPQ( PriorityQueue *ppq );
bool isFullPQ( PriorityQueue *ppq );

#endif
