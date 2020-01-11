#include"stdio.h"
int main()
{
	int a,j,i,m;
	printf("输入一个数将输出它的2倍减一的行数的菱形\n");
	scanf("%d",&a);
	//输出一个i行的三角形
	for(i=0;i<=a;i++)
	{	
		//输出一个倒的空白三角；每行少一个空格	
		for(m=i;m<a;m++)
		{
			printf(" ");
		}
		//输出一个正放的三角；每行多两个星
		for(j=0;j<=2*(i-1);j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=0;i<=a;i++)
	{
		//输出一个正的空白三角；每行多一个空格
		for(m=0;m<=i;m++)
		{
			printf(" ");
		}
		//输出一个倒放的三角；每行少两个星
		for(j=0;j<2*(a-i)-3;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}
