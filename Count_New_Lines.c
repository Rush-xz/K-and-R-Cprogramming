//////////////////////////////////////////////////////////
//
//		program to count New input Lines
//
//////////////////////////////////////////////////////////


//Header
#include<stdio.h>

/*Count Lines in Input*/
int main()
{

	int nl = 0, c = 0; 

	while( getchar() != EOF )
		if( c == '\n' )
			++nl;

	printf("%d\n",nl);

	return 0;
}