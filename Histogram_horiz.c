///////////////////////////////////////////////////////////////////
//
//	Write a program to print a histogram of the lengths of words in its input. 
//	It is easy to draw the histogram with the bars horizont􀍋l; a vertical 
//	orientation is more challenging.	
//
///////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>

#define MAXHIST 	15		 /*Max length of histogram*/
#define MAXWORD 	11		/*Max Length of word*/
#define IN 			1			/*Inside a word*/
#define OUT 		0			/*Outside a word*/
#define BLOCKSIZE   256


/* Print Horizontal histogram 			*/
int main()
{
	int c, i , nc , state , iRet = 0;
	int len ;				/*Length of each bar*/
	int maxvalue;			/*maximum value for each wl[]*/
	int overflow;			/*Number of overflow words*/
	int wl[overflow];		/*Word length Counters*/

	state = 0;
	nc = 0; 		/*Number characters in word*/
	overflow = 0;	/*number of word >= MAXWORD*/

	char arr[BLOCKSIZE];


	for ( i = 0; i < MAXWORD; ++i)
	{
		wl[i]=0;
	}

	int fd = open("Replace_Blanks.c",O_RDONLY);

	while( iRet = read(fd,arr,BLOCKSIZE) )
	{
		for( i=0; i<iRet; ++i)
		{

			if( iRet==' ' || iRet=='\n' || iRet=='\t' )
			{

				state = OUT;

				if( nc > MAXWORD)
				{
					++wl[nc];
				}
				else
				{
					overflow++;
				}
				nc = 0;
			}
			else if( state==OUT )
			{						/*Beggining of new word*/
				state = IN;
				nc = 1;
			}
			else
			{
				nc++;				/*Inside a word*/
			}
		}
	}

	maxvalue = 0;

	for(i = 1;i < MAXWORD;i++)
	{
		if(maxvalue < wl[i])
		{
			maxvalue = wl[i];
		}	
	}


	for(i = 1;i < MAXWORD; i++)
	{
		printf("%5d - %5d",i,wl[i]);

		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
			printf("%d",len);
		}
		else
		{
			len = 0;
		}


		while(len > 0)
		{
			putchar('*');
			--len;
		}

		putchar('\n');
	}

	if(overflow > 0)
	{
		printf("There are %d words that are overflowed\n",overflow);
	}


	return 0;
}

/* OUTPUT

 1 - 6732176601*
    2 - 19357645121*
    3 - 5557707401*
    4 - 5394350691*
    5 - 6899735431*
    6 - 20641897061*
    7 - 1515870821*
    8 - 16685766241*
    9 - 6785846801*
   10 - 1716493791*

*/