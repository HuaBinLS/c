#include"stdio.h"
#include"windows.h"
#include"time.h"
#include"stdlib.h"
main()
{
	//赋值，集合
	int i,t,j,b[15],num;
	//给集合0-51按顺序赋值1-52的数字
	int a[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
	//随机时间，若不加随机，则值是固定的
	srand(time(NULL));
	for(i=0;i<15;i++)
	{
		//随机0-51
		num = rand()%52;
		//如随机到一样的值，则重新随机
		if(a[num]==0)
		{
			i--;
		}
		if(a[num]<=13 && a[num]>=1)
		{
			b[i] = a[num];
			printf("黑桃%d \n",a[num]);
			//将已随机到的数从库中移出
			a[num]=0;
		}		
		else if(a[num]<=26 && a[num]>=14)
		{
			b[i] = a[num];
			printf("红桃%d \n",a[num]-13);
			a[num]=0;
		}	
		else if(a[num]<=39 && a[num]>=27)
		{
			b[i] = a[num];
			printf("草花%d \n",a[num]-26);
			a[num]=0;
		}
		else if(a[num]<=52 && a[num]>=40)
		{	
			b[i] = a[num];
			printf("方块%d \n",a[num]-39);
			a[num]=0;	
		}
	}
	//冒泡排序从大到小
	for(j=0;j<14;j++)
	{
		for(i=0;i<14-j;i++)
		{
			if(b[i]>b[i+1])
			{
				//t相当于再找一个空壳来
				t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
			}
		}
	}
	//打印出结果
	for(i=0;i<15;i++)
	{	
		if(b[i]<=13 && b[i]>=1)
		{
			printf("黑桃%d ",b[i]);
		}
		if(b[i]<=26 && b[i]>=14)
		{
			printf("红桃%d ",b[i]-13);
		}
		if(b[i]<=39 && b[i]>=27)
		{	
			printf("草花%d ",b[i]-26);	
		}
		if(b[i]<=52 && b[i]>=40)
		{
			printf("方块%d ",b[i]-39);	
		}
	}
	system("pause");
}
