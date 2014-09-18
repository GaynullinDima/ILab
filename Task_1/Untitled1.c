
#include <stdio.h>
#include <math.h>

double main(void)
{
	double a, b, c, d;
	int sol_count;
	double x[1];


	printf("A=");
	scanf("%lf", &a);
	printf("B=");
	scanf("%lf", &b);
	printf("C=");
	scanf("%lf", &c);


	sol_count = 2;
	for(i = 0; i < 2; i++)
	 x[i] = 0;


	if (a == 0) {
	  if (b != 0) {
	  sol_count = 1;
	  x[0] =  c / b;
	  }
	  else sol_count = 0;
	}

	else {
	  d = b*b - (4 * a * c);
	  if (d < 0) sol_count = 0;
	  else if (d == 0) {
	   sol_count = 1;
	   x[0] = (- b) / (2 * a);
	  }
	  else {
	  d = sqrt(d);
	  x[0] = (-b + d) / (2 * a);
	  x[1] = (-b - d) / (2 * a);
	  }
	}

	printf("%d %lg %lg", sol_count, x[0], x[1]);
	return(0);
}
