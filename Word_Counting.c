//////////////////////////////////////////////////////////////////
//
//		programs counts lines, words, and characters, with the loose
//		definition that a word is any sequence of characters that 
//		does not contain a blank, tab or newline.
//
//////////////////////////////////////////////////////////////////


//Header
#include<stdio.h>
#define IN 1  /* Inside a Word*/
#define OUT 0	/* Outside a word */


/* count lines, words, and characters in input */
//Entry-Point Function
int main()
{

	int  c = 0, nw = 0, nw = 0, nc = 0, state; 

	state = OUT;

	while( (c = getchar()) != EOF )
	{

		nc++;

		if( c == '\n')
			nw++;

		if( c == ' ' || c== '\n' || c=='\t')
			state = OUT;
		else if( state == OUT )
			state = IN;
			++nw;		
	}

	printf("%d %d %d\n",nl,nw,nc);

	return 0;
}