//////////////////////////////////////////////////////////////////
//
//		write a program to count the number of occurrences of each 
//		digit, of white space characters (blank, tab, newline), 
//		and of all other characters
//
//////////////////////////////////////////////////////////////////


//Header
#include<stdio.h>


/* count digits, white space, others */
//Entry-Point Function
int main()
{

	int  c, i, nwhite, nother; 
	int niDigit[10];

	nwhite = 0;
	nother = 0;

	for( i=0; i<10; i++)
		niDigit[i] = 0;

	while( (c = getchar()) != EOF )
	{

		if( c>=0 && c<=9 )
			++niDigit[c-'0'];
		else if( c==' ' || c=='\n' || c=='\t')
			++nwhite;
		else 
			++nother;
	}

	printf("digits=");
	for( i=0; i<10; i++)
		printf("%d\n",niDigit[i]);

	printf(",white spaces = %d , other = %d\n",nwhite,nother);

	return 0;
}