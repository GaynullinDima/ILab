#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <func.h>

int sol_equation( double a, double b, double c, double*x1, double*x2 )
{
    const int INFINITE_ROOTS = -1;
    double d;
    double x[2];
    int i;
    int solves;

    solves = 2;
	for( i = 0; i < 2; i++ )
	    x[i] = 0;


	if ( a == 0 ) {
        if ( b != 0 ) {
            solves = 1;
            x[0] =  (-c) / b;
        }
        else
        if ( c == 0 ) {
            solves = INFINITE_ROOTS ;       }
        else solves = 0;
	}

	else {
	  d = b*b - (4 * a * c);
	  if ( d < 0 ) solves = 0 ;
	  else if ( d == 0 ) {
        solves = 1;
	    x[0] = ( - b ) / ( 2 * a );
	  }
	  else {
        d = sqrt( d );
        x[0] = ( -b + d ) / ( 2 * a );
        x[1] = ( -b - d ) / ( 2 * a );
	  }
	}

    return(solves);
    x1 = &x[0];
    x2 = &x[1];


}