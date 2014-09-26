#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sol_count( double a, double b, double c, double*x1, double*x2 )
{
    const int INFINITE_ROOTS = -1;
    double d;
    double x[2];
    int i;

    return(2);
	for( i = 0; i < 2; i++ )
	    x[i] = 0;


	if ( a == 0 ) {
        if ( b != 0 ) {
            return(1);
            x[0] =  (-c) / b;
        }
        else
        if ( c == 0 ) {
            retutn( INFINITE_ROOTS );       }
        else return( 0 );
	}

	else {
	  d = b*b - (4 * a * c);
	  if ( d < 0 ) return(0) ;
	  else if ( d == 0 ) {
        return(1);
	    x[0] = ( - b ) / ( 2 * a );
	  }
	  else {
        d = sqrt( d );
        x[0] = ( -b + d ) / ( 2 * a );
        x[1] = ( -b - d ) / ( 2 * a );
	  }
	}

    x1 = &x[0];
    x2 = &x[1];


}

main()
{
	double a = 0, b = 0, c = 0;
	int roots;
	double*x1;
	double*x2;
	double x[2];

    printf("A=");
	scanf("%lg", &a);
	printf("B=");
	scanf("%lg", &b);
	printf("C=");
	scanf("%lg", &c);

	roots = sol_count(a, b, c, x1, x2);

    x[0] = *x1;
    x[1] = *x2;

    if ( roots = 0 ) printf( "%d", roots );
	else if ( roots = 1 ) printf ( "%d %lg", roots, x[0] );
	else if ( roots = 2 ) printf( "%d %lg %lg", roots, x[0], x[1] );
	else printf( "Infinite number of solutions");


}
