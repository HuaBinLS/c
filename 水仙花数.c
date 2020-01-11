#include"stdio.h"
int main()
{
	//赋值
	int a,b,c,d,e,i;
	i=10;
	for(a=1000;a<10000;a++)
	{
		//千位
		b=a/1000;
		//百位
		c=a/100%10;
		//十位
		d=a%100/10;
		//个位
		e=a%10;
		for(i=10;i<100;i++)
		{
			if(b<c && c<d && d<e && i*i==a)
			{
				printf("%d ",a);
			}
		}
	}
system("pause");
}
