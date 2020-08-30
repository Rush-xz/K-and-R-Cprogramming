/*

Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.

*/



#include <stdio.h>
#include <fcntl.h>

#define MAXLINE 1000		 /* maximum input line length */

int getlinex(char  *line);
int Remove(char s[]);

/* print the longest input line */
int main()
{
	char line[MAXLINE]; 	/* current input line */

		while (getlinex(line) > 0)
		{
			if(Remove(line)>0)
				printf("%s\t",line);
		}

		
	return 0;

}


int getlinex(char line[])
{
	int i = 0,c = 0 , fd = 0;
	char arr[256];

	fd = open("Hello.c",O_WRONLY);


	for(i = 0;(i < MAXLINE - 1) && (c = read(fd ,arr,256))!='\0' && (c != '\n'); i++)
	{
		line[i] = c;
	}

	if(c == '\n')
	{
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;
}


//remove trailing blanks and tabs from each line of input
int Remove(char s[])
{
	int i =0;

	while( s[i] != '\n' )		//Find newline character
		i++;
	--i;						//BackOff from '\n'

	while( i>=0 && (s[i]==' ' || s[i]=='\t') )
		--i;

	if( i>=0 )			//is it nonblank line
	{
		++i;
		s[i]='\n';		//Put newline character back
		++i;
		s[i]='\0';		//terminate the string
	}		

	return i;
}
