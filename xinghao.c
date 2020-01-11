#include "stdio.h"
main ()
{
	int a,b,c;
	for (a=1;a<=4;a++)
	{
		for (b=a;b<=4;b++)
		{
			printf (" ");
		}
			for (c=1;c<=a*2-1;c++)
			{	
				printf ("*");
			}
		
		printf ("\n");
	}
	system ("pause"); 
}