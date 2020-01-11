#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"windows.h"

	int x,y,a[10];
	int i,j,p=0;
vivo()
{

	scanf("%d",&x);
	//当输入值大于10时重新输入
	if(x>10)
	{	
	for(p=0;p<2;p++)
		{
			printf("请从新输入！！\n");
			scanf("%d",&x);
		if(x>10)
			{
				p=0;
			}
			if(x<=10)
			{
				break;
			}
		}
	}
	//随机不重复
	srand(time(NULL));
	for(j=0;j<x;j++)
	{
		//取0-999
		a[j]=rand()%1000;
		//若重复就重新随机
		for(i=0;i<j;i++)
		{
			if(a[j]==a[i])
			{
				j--;
			}
		}
	}
	//冒泡排序随机的数
	for(i=0;i<x-1;i++)
	{
		for(j=0;j<(x-1)-i;j++)
		{
			if(a[j]>a[j+1])
			{
				y=a[j];
				a[j]=a[j+1];
				a[j+1]=y;
			}
		}
	}
}
sc()
{
	for(i=0;i<x;i++)
	{
		/*每10个换一行
		if(i>1 && i%10==1)
		{
			printf("\n");

		}
		*/
		printf("%d ",a[i]);
	}
	system("pause");
	
}

main()
{
	vivo();
	sc();
}