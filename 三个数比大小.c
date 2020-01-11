#include "stdio.h"
int main()
{
	int a,b,c;
	int x,z,y;
	puts("请输入三个正整数字：");
	printf ("a=");
	scanf("%d",&a);
	printf ("b=");
	scanf("%d",&b);
	printf ("c=");
	scanf("%d",&c);
	if (a>=b && a>=c)
	{	
		x=a;
		if (c>b)
		{	z=b;
			y=c;
		}
		else if (b>c)
		{	z=c;
			y=b;
		}

	}
	else if (a<b && b>c)
	{
		x=b;
		if (a>c)
		{	z=c;
			y=a;
		}
		else if (c>a)
		{	z=a;
			y=c;
		}
	}
	else if (c>a && c>b)
	{
		x=c;
		if(a>b)
		{	z=b;
			y=a;
		}
		else if (b>a)
		{	z=a;
			y=b; 
		}
	}
	printf("最大值为：%d\n",x);
	printf("最小值为；%d\n",z);
	//以下可用冒泡排序
	if (a<b && a<c && b<c)
	{
		puts("从小到大字母排列为：a<b<c ");
	}
	if (a<c && c<b && a<b)
	{
		puts("从小到大字母排列为：a<c<b ");
	}
		if (c<b && c<a && b<a)
	{
		puts("从小到大字母排列为：c<b<a ");
	}
			if (c<b && c<a && a<b)
	{
		puts("从小到大字母排列为：c<a<b ");
	}
				if (b<a && b<c && a<c)
	{
		puts("从小到大字母排列为：b<a<c ");
	}
					if (b<a && b<c && c<a)
	{
		puts("从小到大字母排列为：b<c<a ");
	}
		printf ("从小到大数字排列为：%d<%d<%d",z,y,x);
	system("pause");
} 

