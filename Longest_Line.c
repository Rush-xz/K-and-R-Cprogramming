/* 			print the longest input line 			*/



#include <stdio.h>
#include <fcntl.h>

#define MAXLINE 1000		 /* maximum input line length */

int getlinex(char  *line);
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
int getlinex(char* line)
{
	int i = 0,c = 0 , fd = 0;
	char arr[256];

	fd = open("tp.txt",O_RDONLY);

	while(i < MAXLINE-1 && (c = read(fd , arr , 256) ) !='\0' && c != '\n')
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



#include<stdio.h>
#include<fcntl.h>
#define MAXLINE     100

int getlinex(char line[]);
void reverse(char line[]);

int main()
{
    char line[MAXLINE];
   // int len = 0;

    while(getlinex(line) > 0)
    {
        reverse(line);
        printf("%s",line);
    }
    return 0;
}

int getlinex(char line[])
{
    int i = 0,c = 0;
    int fd = 0;
    char arr[256];

    fd = open("tp.txt",O_RDONLY);

    for(i = 0;(i < (MAXLINE -1)) && (c = read(fd,arr,256) != '\0') && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void reverse(char line[])
{
    printf("Inside Reverse\n");
    int i = 0,j = 0;
    char temp;

    while(line[i]!='\0')
        ++i;
    --i;

    if(line[i]=='\n')
        --i;

    while(j<i)
    {

        temp = line[j];
        line[j] = line[i];
        line[i] = temp;

        i--;
        j++;
    }

}