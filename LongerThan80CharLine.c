/*

Write a program to print all input lines that are longer than 80 characters.

*/


#include <stdio.h>
#include <fcntl.h>

#define MAXLINE 1000		 /* maximum input line length */
#define LONGLINE 80

int getlinex(char  line[] , int MAXLINE);


/* print lines longer than LONGLINE */
int main()
{
	int len; 				/* current line length */
	char line[MAXLINE]; 	/* current input line */

		while ((len = getlinex(line)) > 0)
		{
			if (len > LONGLINE) 
			{
				printf("%s",line);		
			}
		}

	return 0;

}


/* getlinex: read a line into line, return length */
int getlinex(char line[] , int MAXLINE)
{
	int i = 0,c = 0 , fd = 0;
	char arr[256];

	fd = open("tp.txt",O_RDONLY);

	while((c = read(fd , arr , 256) ) !='\0' && c != '\n')
	{
		*(line+i) = c;
		i++;
	}
	if(c == '\n')
	{
		*(line+i)  = c;
		i++;
	}

	*(line+i) = '\0';

	printf("%d\n",i);

	return i;
}