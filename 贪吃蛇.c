#include"stdio.h"
#include"windows.h"
#include"stdlib.h"
#include"time.h"
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)//ģ�����

struct pos
{
	int x;
	int y;
};
int x,y,i,j,lon=3;
struct  pos player[122]={{9,9},{9,8},{9,7}};
//ʳ��
struct pos food= {0,0};
//����ֵ
int YesNo;
//�����Ƿ��ӡ
int playerlong;
//����
struct pos dir={-1,0};
//ѭ��
int run=1;
int runfood;
int map[14][14] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,3,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,4,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

//��ʼ��
void Init()	
{
	srand(time(NULL));
	food.x = rand()%12+1;
	food.y = rand()%12+1;
	lon=3;
	dir.x=-1,dir.y=0;
	//�����������
	memset(&player,0,sizeof(player));
	player[0].x=9,player[0].y=9;
	player[1].x=9,player[1].y=8;
	player[2].x=9,player[2].y=7;
}


//����
void control()
{
	//����ƶ�
	if(KEYDOWN(VK_UP) && dir.x!=0)
	{
			dir.y = -1;
			dir.x = 0;
		
	}
	else if(KEYDOWN(VK_DOWN) && dir.x!=0)
	{
			dir.y = 1;
			dir.x = 0;
	}
	else if(KEYDOWN(VK_LEFT) && dir.y!=0)
	{
			dir.y = 0;
			dir.x = -1;
	}
	else if(KEYDOWN(VK_RIGHT) && dir.y!=0)
	{
			dir.y = 0;
			dir.x = 1;
	}
}
//�߼�
void Updata()
{
	//β���ȶ�
	for(i=lon;i>=1;i--)
	{
		player[i].x = player[i-1].x;
		player[i].y = player[i-1].y;
	}


	//ÿһ֡����һ������
	player[0].x +=dir.x;
	player[0].y +=dir.y;

	//������
	if(map[player[0].x][player[0].y] ==3)
	{
			player[0].x=10;
			player[0].y=10;
	}
	else if(map[player[0].x][player[0].y] ==4)
	{
			player[0].x=3;
			player[0].y=2;
	}

	//ײǽ����
	if(map[player[0].x][player[0].y] ==1)
	{
		YesNo = MessageBox(NULL,"������","��ʾ",MB_YESNO);
		if(YesNo == IDYES)
		{
			Init();
		}
 		else if(YesNo == IDNO)
		{
			run=0;
		}
	}
	//�Ե�ʳ��
	if(player[0].x==food.x && player[0].y==food.y)
	{
		runfood=1;
		while(runfood)
		{
			food.x = rand()%12+1;
			food.y = rand()%12+1;
			runfood=0;
			for(j=0;j<=lon;j++)
			{
				if(food.x == player[j].x && food.y == player[j].y)
				{
					runfood=1;
				}
			}
		}
	
		lon +=1;
	//�������Ͻ���ʾһ������
		player[lon-1].x=-1;
		player[lon-1].y=-1;
	}
	//ײ��������
	for(i=1;i<=lon;i++)
	{
		if(player[0].x == player[i].x && player[0].y == player[i].y)
		{
			YesNo = MessageBox(NULL,"������","��ʾ",MB_YESNO);
			if(YesNo == IDYES)
			{
				Init();
			}
 			else if(YesNo == IDNO)
			{
				run=0;
			}
		}
	
	}

}
//��Ⱦ
void Render()
{
	for(y=0;y<14;y++)
	{
		for(x=0;x<14;x++)
		{
			playerlong = 0;
			for(i=0;i<lon;i++)
			{	
				//�ж��Ƿ��ӡ����
				if(x==player[i].x && y==player[i].y)
				{
					playerlong = 1;
				}
			
			}
			if(player[0].x==x && player[0].y==y )
			{
				printf("��");
			}
			else if(playerlong ==1)
			{
				printf("β");
			}
			else if(y == food.y && x == food.x)
			{
				printf("��");
			}
			else if(map[x][y]>2 &&map[x][y]<=4)
			{
				printf("��");
			}
			else if(map[x][y] == 1)
			{
				printf("��");
			}
			else if(map[x][y] == 0)
			{
				printf("  ");
			}
	
		}
		printf("\n");
	}
	Sleep(50);
	system("cls");
}


main()
{
	Init();
	while(run)
	{
		control();
		Updata();
		Render();
	
	}

}