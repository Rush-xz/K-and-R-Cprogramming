//////////////////////////////////////////////////////////
//
//		Write a program to count blanks, tabs, and newlines.
//
//////////////////////////////////////////////////////////


//Header
#include<stdio.h>

/*Count Lines in Input*/
int main()
{

	int count = 0, c = 0; 

	while( getchar() != EOF )
		if( (c == '\n') || (c=='\b') || (c=='\t') )
			++count;

	printf("%d\n",count);

	return 0;
}