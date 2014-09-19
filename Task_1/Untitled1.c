
#include <stdio.h>
#include <math.h>

main()
{
	double a = 0, b = 0, c = 0, d = 0;
	int sol_count;
	double x[2];


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
            x[0] =  (-c) / b;
        }
        else
        if (c == 0) {
            printf ("infinite number of solutions");
            exit(1);
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

	if (sol_count = 0) printf("%d", sol_count);
	else if (sol_count = 1) printf ("%d %lf", sol_count, x[0]);
	else printf("%d %lf %lf", sol_count, x[0], x[1]);
}
