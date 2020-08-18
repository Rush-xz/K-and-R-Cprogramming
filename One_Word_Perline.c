//////////////////////////////////////////////////////////////////
//
//		Write a program that prints its input one word per line.
//
//////////////////////////////////////////////////////////////////


//Header
#include<stdio.h>
#define IN 1  /* Inside a Word*/
#define OUT 0	/* Outside a word */


/*prints its input one word per line.*/
//Entry-Point Function
int main()
{

	int  c = 0,  state; 

	state = OUT;

	while( (c = getchar()) != EOF )
	{

		if( c == ' ' || c== '\n' || c=='\t')	//Finish the word

			if( state == IN)
				putchar("\n");
				state = OUT;

		else if( state == OUT )		//Beggining of word

			state = IN;
			putchar(c);

		else						//Inside a word

			putchar(c);
	}

	return 0;
}