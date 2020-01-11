#include <stdio.h>
#include <conio.h>  
#include <time.h>  
#define ESC 27  
int main(int argc, char** argv)
{	
	clock_t start, end;	char ch;		
	printf("\n\t\t\t\t\t *****秒表***** \n\n");	
	printf("\t(1)按't'开始计时  (2)按'p'暂停计时并显示当前计时时长  (3)按'c'使秒表归零  (4)按'Esc'退出程序\n\n");	// 按't'键开始计时 
	if(getch() == 't')	
	{		
		printf("已开始计时...");		// 返回开始计时时间 		
		start = clock(); 		// for(;;) 等效于 while(1) 		
		for(;;)		
		{		
			ch = getch();			// 按'p'键暂停计时  		
			if(ch == 'p')
			{			
				for(;;)
				{					// 返回结束计时时间 				
					end = clock();		
					printf("\n\n已暂停计时, 再按'p'开始计时. 显示当前计时时长 : %f\n", 					((double)(end - start) / CLOCKS_PER_SEC));  // CLOCKS_PER_SEC 等效于 CLK_TCK, 但后者已过时 							// 再次按'p'键开始计时 					
					if(getch() == 'p')
					{						
						printf("\n\n继续计时...");							break;				
			
					}			
			
				}		
			}				// 按'c'键秒表归零			
		
			if(ch == 'c')
					
			{				
						printf("\n\n秒表已归零.\n");			
						start = clock(); 		
					
			}			
			// 按'Esc'键退出程序				
					
			if(ch == ESC)			
						break;		
		}	
			
	}
		return 0;
	}		
				
