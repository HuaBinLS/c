#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main()
{
	//  集合，赋值 
	int a[10],i,c=0;
	float b=0;
	//随机时间，若不加随机，则值是固定的
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		//给集合随机值
		a[i]= rand()%100;
		printf("%d ",a[i]); 
		//随机值求和
		b+=a[i];
		//求集合里的最大值
		if(a[i]>c)
		{
			c=a[i];
		}	
	}	
	printf("\n%d ",c);
	//求平均数
	b/=10.0;
	printf("\n%.1f \n",b);
system("pause");	
}