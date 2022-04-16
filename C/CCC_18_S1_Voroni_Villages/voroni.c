/******************************************************************************
 * Filename:  voroni.c                                                        *
 * Author: Nicholas Wright 12880155                                           *
 * Purpose:                                                                   *
 * Assertions- PRE:                                                           *
 *            POST:                                                           *
 * Date Written:                                                              *
 * Edited By:       Date Edited:                                              *
 * ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LEFT_DIFF(i) villageLocations[( i )] - villageLocations[( i-1 )]
#define RIGHT_DIFF(i) villageLocations[( i+1 )] - villageLocations[( i )]

void sortArray( int *array, int size )
{
    int temp, n;
    for( n=1; n  < size; n++ )
    {
        int i=n;
        while( ( i>0 ) && ( array[i-1] > array[i] ) )
        {
            temp = array[i];
            array[i] = array[i-1];
            array[i-1] = temp;
            i = i-1;
        }
    }
}

int main( )
{
    int i, numOfVillages = 0;
    int *villageLocations;
    double smallDiff = 0.0f, tempDiff = 0.0f;
    scanf( "%d", &numOfVillages );

    villageLocations = (int*)malloc( sizeof( int ) * numOfVillages );

    for( i = 0; i < numOfVillages; i++ )
    {
        scanf( "%d", &( villageLocations[i] ) );
    }

    sortArray( villageLocations, numOfVillages );

    tempDiff = ( ( (double)( LEFT_DIFF(1) )/ 2.0f ) +
               ( (double)( RIGHT_DIFF(1) ) / 2.0f ) );
    smallDiff = tempDiff;

    for( i=2; i < ( numOfVillages-1 ); i++ )
    {
        tempDiff = ( ( (double)( LEFT_DIFF(i) ) / 2.0f ) +
                     ( (double)( RIGHT_DIFF(i) ) / 2.0f ) );

        if( tempDiff < smallDiff )
        {
            smallDiff = tempDiff;
        }
    }
    printf( "%.1f", smallDiff );

    free( villageLocations );
    return 0;
}
