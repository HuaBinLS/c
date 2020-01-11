#include "stdio.h"
main()
{
	int a,b,c;
	for (a=0;a<=59;a++)
	{
		for (b=0;b<=59;b++)
		{
			for (c=0;c<=59;c++)
			{
				printf ("%d:%d:%d",a,b,c);
				system("cls");
			}
			printf ("%d:%d:%d",a,b,c);
			system("cls");
		}
		printf ("%d:%d:%d",a,b,c);
		system("cls");
	}
	
	
	
	system("pause");
}

