#include"stdio.h"
#include"windows.h"
#include"time.h"
#include"stdlib.h"
main()
{
	//��ֵ������
	int i,t,j,b[15],num;
	//������0-51��˳��ֵ1-52������
	int a[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
	//���ʱ�䣬�������������ֵ�ǹ̶���
	srand(time(NULL));
	for(i=0;i<15;i++)
	{
		//���0-51
		num = rand()%52;
		//�������һ����ֵ�����������
		if(a[num]==0)
		{
			i--;
		}
		if(a[num]<=13 && a[num]>=1)
		{
			b[i] = a[num];
			printf("����%d \n",a[num]);
			//��������������ӿ����Ƴ�
			a[num]=0;
		}		
		else if(a[num]<=26 && a[num]>=14)
		{
			b[i] = a[num];
			printf("����%d \n",a[num]-13);
			a[num]=0;
		}	
		else if(a[num]<=39 && a[num]>=27)
		{
			b[i] = a[num];
			printf("�ݻ�%d \n",a[num]-26);
			a[num]=0;
		}
		else if(a[num]<=52 && a[num]>=40)
		{	
			b[i] = a[num];
			printf("����%d \n",a[num]-39);
			a[num]=0;	
		}
	}
	//ð������Ӵ�С
	for(j=0;j<14;j++)
	{
		for(i=0;i<14-j;i++)
		{
			if(b[i]>b[i+1])
			{
				//t�൱������һ���տ���
				t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
			}
		}
	}
	//��ӡ�����
	for(i=0;i<15;i++)
	{	
		if(b[i]<=13 && b[i]>=1)
		{
			printf("����%d ",b[i]);
		}
		if(b[i]<=26 && b[i]>=14)
		{
			printf("����%d ",b[i]-13);
		}
		if(b[i]<=39 && b[i]>=27)
		{	
			printf("�ݻ�%d ",b[i]-26);	
		}
		if(b[i]<=52 && b[i]>=40)
		{
			printf("����%d ",b[i]-39);	
		}
	}
	system("pause");
}
