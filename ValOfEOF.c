//////////////////////////////////////////////////////////
//
//	Write the program to print the value of EOF
//
//////////////////////////////////////////////////////////


//Header
#include<stdio.h>


//Entry Point Function
int main()
{
	
	printf(" Value of EOF is %4d.\n",EOF);

	return 0;
}

/* Output

Value of EOF is   -1.

*/

/*
The symbolic constant EDF is defined in <stdio.h>. The EDF outside the
double quotes in printf C > is replaced by whatever text follows

#define EDF

in the include file. In our system EDF is - 1, but it may vary from system to
system. That's why standard symbolic constants like EOF help make your program
portable.
*/