#include "stdio.h"
#include "windows.h"
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
//��������
	struct pos
	{
		int x;
		int y;
	};
	struct pos player = {1,1};
	struct pos OLD;
	struct pos box[4] ={{1,2},{3,3},{3,4},{5,5}};
	struct pos gon[4] ={{1,8},{7,1},{8,3},{1,1}};
	struct pos playerDir;
	struct pos GDD;
	int x,y,i,j;
	//�жϸ������Ƿ�Ҫ�������
	int isPrintBox = 0,isprintgon=0;
	int	isprintwin0 = 0;
	int null=1;

	int map[10][10] =  {{1,1,1,1,1,1,1,1,1,1},
						{1,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,1,0,1},
						{1,0,0,0,1,0,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,1},
						{1,0,1,1,1,0,0,0,0,1},
						{1,0,1,0,0,0,0,1,0,1},
						{1,1,1,1,1,1,1,1,1,1}};



//����
void control()
{


		//�߼��ж�
		//�ƶ�ǰ ���µ�ǰ����
		OLD.x = player.x;
		OLD.y = player.y;
		//����ƶ�
		if(KEYDOWN(VK_UP))	 
		{
			player.y--;
			playerDir.x =0;
			playerDir.y =-1;
		}
		if(KEYDOWN(VK_DOWN))
		{
			player.y++;
			playerDir.x =0;
			playerDir.y =1;
		}
		if(KEYDOWN(VK_LEFT))
		{
			player.x--;
			playerDir.x =-1;
			playerDir.y =0;
		}
		if(KEYDOWN(VK_RIGHT))
		{
			player.x++;
			playerDir.x =1;
			playerDir.y =0;
		}
		//�ƶ����ж��Ƿ�Ƕ��ǽ��(�����������뵽��ͼ�Ͽ��ǲ���Ϊ1)
		//���Ƕ��ǽ�ڣ������˻�ԭ��λ��
		if(map[player.y][player.x] == 1)
		{
			player.x = OLD.x;
			player.y = OLD.y;
		}
}
//�ж�
void updata()
{
	//else if()
		//�ж��Ƿ�ײ��ĳ������

		for(i=0;i<4;i++)
		{	
			//�������ӵ�ԭ����
				GDD.x = box[i].x;
				GDD.y = box[i].y;
			//�ж��Ƿ�ĳ���������������غ�
			if(box[i].x == player.x && box[i].y == player.y)
			{
			
				//���Ӱ�������ƶ��ķ�������ƶ�
				box[i].x += playerDir.x;
				box[i].y += playerDir.y;
			}
			//����ƶ����λ����ǽ
			if(map[box[i].y][box[i].x] == 1)
			{
				//�˻�ԭ����
				box[i].x = GDD.x;
				box[i].y = GDD.y;
				//���Ҳ�˻�ԭ����
				player.x = OLD.x;
				player.y = OLD.y;
			}
			for(j=0;j<4;j++)
			{
				if(j !=i && box[i].x==box[j].x && box[i].y==box[j].y)
				{
				
					//�˻�ԭ����
					box[i].x = GDD.x;
					box[i].y = GDD.y;
					//���Ҳ�˻�ԭ����
					player.x = OLD.x;
					player.y = OLD.y;
				}
			}
		}
			//�ж������Ƿ��ڵ���
				isprintwin0 = 0;
			for(j=0;j<4;j++)
			{
				for(i=0;i<4;i++)
					{
					if(box[j].y == gon[i].y && box[j].x == gon[i].x)
						{
							isprintwin0 +=1;
						}
					if(isprintwin0 ==4)
						{
						MessageBox(NULL,"��ϲ��Ӯ��","��ʾ",MB_OK);
						null =0;
						}
					}
			}
}
//��Ⱦ
void render()
{
			//��Ⱦ
			for (y=0;y<10;y++)
			{
				for(x=0;x<10;x++)
				{
				
					isPrintBox = 0;
					isprintgon = 0;
					for(i=0;i<4;i++)
					{
						if(y == gon[i].y && x == gon[i].x)
						{
							isprintgon = 1;
					
						}
						
						if(x == box[i].x && y == box[i].y)
						{	
							isPrintBox = 1;
							
						}
					}
					if(y==player.y && x==player.x)
					{
						printf("��");
					}
					//���Ӻ͵���һ�����Ⱦ
					else if (isprintgon == 1 && isPrintBox ==1) 
					{
						printf("��");
					}
					else if(isPrintBox ==1)
					{
						printf("��");
					}
					else if(isprintgon == 1)
					{
						printf("��");
					}	
					else if(map[y][x] == 1)
					{
						printf("��");
					}
					else if(map[y][x] == 0)
					{
						printf("  ");
					}
				
				}
				printf("\n");
			}
			Sleep(10);
			system("cls");
}

main()
{
	while(null)
	{
		control();
		updata();
		render();
	}
}
