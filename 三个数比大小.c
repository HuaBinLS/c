#include "stdio.h"
int main()
{
	int a,b,c;
	int x,z,y;
	puts("�����������������֣�");
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
	printf("���ֵΪ��%d\n",x);
	printf("��СֵΪ��%d\n",z);
	//���¿���ð������
	if (a<b && a<c && b<c)
	{
		puts("��С������ĸ����Ϊ��a<b<c ");
	}
	if (a<c && c<b && a<b)
	{
		puts("��С������ĸ����Ϊ��a<c<b ");
	}
		if (c<b && c<a && b<a)
	{
		puts("��С������ĸ����Ϊ��c<b<a ");
	}
			if (c<b && c<a && a<b)
	{
		puts("��С������ĸ����Ϊ��c<a<b ");
	}
				if (b<a && b<c && a<c)
	{
		puts("��С������ĸ����Ϊ��b<a<c ");
	}
					if (b<a && b<c && c<a)
	{
		puts("��С������ĸ����Ϊ��b<c<a ");
	}
		printf ("��С������������Ϊ��%d<%d<%d",z,y,x);
	system("pause");
} 

