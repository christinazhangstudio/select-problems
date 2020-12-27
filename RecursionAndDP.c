#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const char DATA_FILE_NAME[] = "TestData.txt";

typedef struct functionRuntimes
{
    char *name;             //name of the function being tested
    double **times;         //run times
    double *stddev;         //standard deviation
    int numTestCases;       //number of times to repeat each test size
    int numTestCaseSizes;   //number of test sizes
    int *testCaseSizes;     //array containing the test sizes
} functionRuntimes;

typedef enum boolean { FALSE, TRUE } boolean;

functionRuntimes timeAlgorithm( char*, int, int, int[], boolean (*f)(int) );
FILE *generateTestInput( int, int, int );
void computeAvg( functionRuntimes fRT );
void printRuntimeTable( functionRuntimes fRT );
void freeFunctionRuntimes( functionRuntimes fRT );

boolean recursiveSolution( int n );
boolean recursiveSolutionDPInitial( int n );
boolean recursiveSolutionDP( int n, int dpTable[]);

int main( int argc, char *argv[] )
{
    functionRuntimes fRT;

    int sizes1[] = { 30, 40, 50, 65 };
    int sizes2[] = { 30000, 40000, 50000, 65000 };

    //Code to print out solution for first 99 cases
    /*for( i=1; i<100; i++){
        if( recursiveSolutionDPInitial(i) )
            printf("For n=%2d, player 1 wins\n", i);
        else
            printf("For n=%2d, player 2 wins\n", i);
    }*/

    fRT = timeAlgorithm("No DP", 4, 3, sizes1, recursiveSolution );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("with DP", 4, 4, sizes2, recursiveSolutionDPInitial );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);


    return 0;
}

/* provided code - DO NOT CHANGE
 * Recursive solution without dynamic programming
 * Returns true if the next player to move can win from the current state, otherwise return false
 */
boolean recursiveSolution( int n )
{
    if( n<1 )
        return TRUE;
    else if( n==1 )
        return FALSE;
    else if( !recursiveSolution( n-1 ) || !recursiveSolution( n-2 ) || !recursiveSolution( n/2 ) )
        return TRUE;
    else
        return FALSE;
}

/* provided code - DO NOT CHANGE
 * Recursive solution with dynamic programming
 * Returns true if the next player to move can win from the current state, otherwise return false
 */
boolean recursiveSolutionDPInitial( int n )
{
    int *dpTable = (int *)malloc( (n+1)*sizeof(int) );
    int i;
    boolean ret;

    for( i=0; i<n+1; i++)
    {
        dpTable[i] = -1;
    }

    ret = recursiveSolutionDP( n, dpTable );
    //printf( "%d\n", ret );
    free( dpTable );
    return ret;
}

/* provided code - DO NOT CHANGE
 * Recursive solution with dynamic programming
 * Returns true if the next player to move can win from the current state, otherwise return false
 */
boolean recursiveSolutionDP( int n, int dpTable[] )
{
    if( dpTable[n] == -1 )
    {
        if( n<1 )
            return TRUE;
        else if( n==1 )
            return FALSE;
        else if( !recursiveSolutionDP( n-1, dpTable ) || !recursiveSolutionDP( n-2, dpTable ) || !recursiveSolutionDP( n/2, dpTable ) )
            dpTable[n] = TRUE;
        else
            dpTable[n] = FALSE;
    }
    return dpTable[n];
}


/*************************************** Functions for finding and printing runtime *********************************************/

functionRuntimes timeAlgorithm( char *name, int numTestCases, int numTestCaseSizes, int testCaseSizes[], boolean (*f)(int) )
{
    /* Call and calculate the runtime of the provided function */
    clock_t start, end;
    int i, j;

    //create functionRuntimes variable to return
    functionRuntimes fRT;
    //copy passed data into the functionRuntimes variable
    fRT.name = name;
    fRT.numTestCases = numTestCases;
    fRT.numTestCaseSizes = numTestCaseSizes;
    fRT.testCaseSizes = testCaseSizes;


    //initialize and fill in the runtimes table
    fRT.times = (double **)malloc( numTestCaseSizes*sizeof(double *) );
    for( i=0; i<numTestCaseSizes; i++ )
    {
        fRT.times[i] = (double *)malloc( numTestCases*sizeof(double) );

        for( j=0; j<numTestCases; j++ )
        {
            //printf("Entered for %d\n", j);
            //printf("Gen-ed for %d\n", testCaseSizes[i]);

            start = clock();
            f( testCaseSizes[i] );
            end = clock();
            //printf("start = %lu, end = %lu\n", start, end);
            //printf("Tested for %d\n", j);

            fRT.times[i][j] = (double)(end - start) / CLOCKS_PER_SEC;
            //printf("fRT.times[%d][%d] = %.3lf seconds\n", i, j, fRT.times[i][j]);
        }
    }

    return fRT;
}

void printRuntimeTable( functionRuntimes fRT )
{
    int i, j;

    printf( "\n%s", fRT.name );
    printf( "\nTest size " );
    for( j=0; j<fRT.numTestCases; j++ )
    {
        printf( "Test #%d   ", j );
    }
    printf( "\n" );

    for( i=0; i<fRT.numTestCaseSizes; i++ )
    {
        printf( "%-10d", fRT.testCaseSizes[i] );
        for( j=0; j<fRT.numTestCases; j++ )
        {
            printf( "%-9.3lf ", fRT.times[i][j] );
        }
        printf( "\n" );
    }
}

void freeFunctionRuntimes( functionRuntimes fRT )
{
    int i;

    for( i=0; i<fRT.numTestCaseSizes; i++ )
    {
        free( fRT.times[i] );
    }
    free( fRT.times );
}

