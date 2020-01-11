#include "stdio.h"
#include "windows.h"
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
//公共部分
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
	//判断该坐标是否要输出箱子
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



//控制
void control()
{


		//逻辑判断
		//移动前 存下当前坐标
		OLD.x = player.x;
		OLD.y = player.y;
		//玩家移动
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
		//移动后，判断是否嵌进墙壁(把玩家坐标代入到地图上看是不是为1)
		//如果嵌进墙壁，我们退回原来位置
		if(map[player.y][player.x] == 1)
		{
			player.x = OLD.x;
			player.y = OLD.y;
		}
}
//判断
void updata()
{
	//else if()
		//判断是否撞到某个箱子

		for(i=0;i<4;i++)
		{	
			//保留箱子的原坐标
				GDD.x = box[i].x;
				GDD.y = box[i].y;
			//判断是否某个箱子坐标和玩家重合
			if(box[i].x == player.x && box[i].y == player.y)
			{
			
				//箱子按照玩家移动的方向进行移动
				box[i].x += playerDir.x;
				box[i].y += playerDir.y;
			}
			//如果移动后的位置是墙
			if(map[box[i].y][box[i].x] == 1)
			{
				//退回原坐标
				box[i].x = GDD.x;
				box[i].y = GDD.y;
				//玩家也退回原坐标
				player.x = OLD.x;
				player.y = OLD.y;
			}
			for(j=0;j<4;j++)
			{
				if(j !=i && box[i].x==box[j].x && box[i].y==box[j].y)
				{
				
					//退回原坐标
					box[i].x = GDD.x;
					box[i].y = GDD.y;
					//玩家也退回原坐标
					player.x = OLD.x;
					player.y = OLD.y;
				}
			}
		}
			//判断箱子是否在点上
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
						MessageBox(NULL,"恭喜你赢了","提示",MB_OK);
						null =0;
						}
					}
			}
}
//渲染
void render()
{
			//渲染
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
						printf("★");
					}
					//箱子和点在一起的渲染
					else if (isprintgon == 1 && isPrintBox ==1) 
					{
						printf("▲");
					}
					else if(isPrintBox ==1)
					{
						printf("□");
					}
					else if(isprintgon == 1)
					{
						printf("○");
					}	
					else if(map[y][x] == 1)
					{
						printf("■");
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
