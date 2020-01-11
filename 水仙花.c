#include "stdio.h"
main ()
{
	int a,b,c,d,e,f;
	for (a=1000;a<10000;a++)
	{	
		b=a/1000;
		c=a%1000/100;
		d=a%100/10;
		e=a%10;
		
		if (b<c&&c<d&&d<e)
		{
		for (f=10;f<100;f++)
		{
			if (f*f==a)
		
			printf ("%d ",a);
		}
		}
	}
	system ("pause");
}