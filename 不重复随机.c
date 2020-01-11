#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"windows.h"
main()
{
	//赋值
	int a,i,j;
	//一个集合
	int b[10];
	//随机时间，若不加随机，则值是固定的
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		//随机0-99
		b[i]=rand()%100;
		for(j=0;j<i;j++)
		{
			if(b[i]==b[j])
			{
				i--;
			}
		}
	}
	//每随机一次打印一个值
	for(i=0;i<10;i++)
	{
		printf("%d ",b[i]);
	}
	system("pause");
}