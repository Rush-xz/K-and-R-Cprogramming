#include<stdio.h>

/* print Celsius-Fahrenheit table
for celsius = 0, 20, ..., 300; floating-point version */


#define	LOWER 0		/* LOWER Limit */
#define	UPPER 300	/* UPPER Limit */
#define STEPS 20	/* step size */

int main()
{
	float fahr ;
	int  celsius;
	
	celsius = LOWER;

	printf("\n \"Celsius-Fahrenheit conversion table\" \n");
	while( celsius <= UPPER)
	{

		fahr =  ( (9.0/5.0)*celsius ) + 32;

		printf("%5d %8.2f \n",celsius,fahr);

		celsius = celsius + STEPS;
	}
}

/*	Output

 "Celsius-Fahrenheit conversion table"
    0    32.00
   20    68.00
   40   104.00
   60   140.00
   80   176.00
  100   212.00
  120   248.00
  140   284.00
  160   320.00
  180   356.00
  200   392.00
  220   428.00
  240   464.00
  260   500.00
  280   536.00
  300   572.00
*/
