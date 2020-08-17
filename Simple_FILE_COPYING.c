//////////////////////////////////////////////////////////
//
//		program that copies its input to its output one 
//		character at a time
//
//////////////////////////////////////////////////////////


//Header
#include<stdio.h>

/* copy input to output; 1st version */
//Entry Point Function
int main()
{	
	int c;

	c = getchar();

	while (c != EOF) 
	{
		putchar(c);

		c = getchar();
	}

	return 0;
}

/* copy input to output; 2nd version 

int main()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);

}

*/