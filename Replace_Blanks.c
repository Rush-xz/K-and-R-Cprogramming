/*
	
	Write a program to copy its input to its output, replacing each 
	string of one or more blanks by a single blank.

*/

//Header
#include <stdio.h>
#define NOTBLANK 'a'

int int main()
{

	int c = 0 , lastc = 0;


	lastc = NOTBLANK;
	
	while( getchar() != EOF )
	{
		if( c != ' ')
		{
			putchar(c);
		}
		else if( lastc != ' ')
		{
			putchar(c);
		}

		lastc = c;
	}

	return 0;
}

/*

int main()
{

	int c;

	while( c=getchar() != EOF )
	{

		if( (c!=' ') || ( lastc != ' ') )
		{
			putchar(c);
		}

		lastc = c;
	}
}

*/