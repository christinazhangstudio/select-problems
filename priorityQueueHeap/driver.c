#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "priorityQueueInt.h"

int main( int argc, char* argv[] )
{
    int i;
    int numRepeats = 10;
    pqType pt;
    PriorityQueue *ppq = createPQ();

    srand( time(NULL) );

    for( i=0; i<numRepeats; i++ ){

        printf( "ADDED: " );
        do{
            pt.info = pt.priority = rand()%100;
            insertPQ( ppq, pt );
            printf( "%d ", pt.info );
        }while( rand()%5 != 0 );
        printf( "\n" );

        printf( "REMOVED: %d\n", removePQ( ppq ).info );
    }

    while( !isEmptyPQ(ppq) )
        removePQ( ppq );

    freePQ(ppq);

    return 0;
}
