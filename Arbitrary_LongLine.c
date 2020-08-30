/* 			
	Revise the main routine of the longest-line program so it will correctly print the
length of arbitrarily long input lines. and as much as possible of the text.

			*/



#include <stdio.h>
#include <fcntl.h>

#define MAXLINE 1000	 /* maximum input line length */

int getlinex(char  line[] , int MAXLINE);
void copy(char  to[], char  from[]);

/* print the longest input line */
int main()
{
	int len; 				/* current line length */
	int max; 				/* maximum length seen so far */
	char line[MAXLINE]; 	/* current input line */
	char longest[MAXLINE];  /* longest line saved here */
	max = 0;

		while ((len = getlinex(line)) > 0)
		{
			printf("%d,%s\n",len,line);
			if (len > max) 
			{
				max = len;

				copy(longest, line);
			}
		}

		if (max > 0) 		/* there was a line */
			printf("%s",longest);

	return 0;

}


/* getlinex: read a line into line, return length */
int getlinex(char line[] , int lim)
{
	int i = 0, =0 , c = 0 , fd = 0;
	char arr[256];

	fd = open("tp.txt",O_RDONLY);

	while((c = read(fd , arr , 256) ) !='\0' && c != '\n')
		if(i<lim-2)
		{
			*(line+i) = c;		//Line Still in boundries
			j++;
		}

	if(c == '\n')
	{
		*(line+i)  = c;
		i++;
		j++;
	}

	*(line+i) = '\0';

	printf("%d\n",i);

	return i;
}

/*
getlinex(char line[])
{
	int i = 0,c = 0;
	for(i = 0;(i < MAXLINE - 1) && (c = getchar()) !=EOF && (c != '\n'); i++)
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
}*/

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;

}

/*void copy(char *to,char *from)
{
	while(*from != '\0')
	{
		*to++ = *from++;
	}
	*to = '\0';
}*/



