#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"windows.h"

	int x,y,a[10];
	int i,j,p=0;
vivo()
{

	scanf("%d",&x);
	//������ֵ����10ʱ��������
	if(x>10)
	{	
	for(p=0;p<2;p++)
		{
			printf("��������룡��\n");
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
	//������ظ�
	srand(time(NULL));
	for(j=0;j<x;j++)
	{
		//ȡ0-999
		a[j]=rand()%1000;
		//���ظ����������
		for(i=0;i<j;i++)
		{
			if(a[j]==a[i])
			{
				j--;
			}
		}
	}
	//ð�������������
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
		/*ÿ10����һ��
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