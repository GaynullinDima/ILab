#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <func.h>

int main(void)
{
	double a = 0, b = 0, c = 0;
	int roots;
	double*x1;
	double*x2;

    printf("A=");
	scanf("%lg", &a);
	printf("B=");
	scanf("%lg", &b);
	printf("C=");
	scanf("%lg", &c);

	roots = sol_equation(a, b, c, x1, x2);


    if ( roots == 0 ) printf( "%d", roots );
	else if ( roots == 1 ) printf ( "%d %lg", roots, *x1 );
	else if ( roots == 2 ) printf( "%d %lg %lg", roots, *x1, *x2 );
	else printf( "Infinite number of solutions");


}
