#include <stdio.h>
#include <conio.h>  
#include <time.h>  
#define ESC 27  
int main(int argc, char** argv)
{	
	clock_t start, end;	char ch;		
	printf("\n\t\t\t\t\t *****���***** \n\n");	
	printf("\t(1)��'t'��ʼ��ʱ  (2)��'p'��ͣ��ʱ����ʾ��ǰ��ʱʱ��  (3)��'c'ʹ������  (4)��'Esc'�˳�����\n\n");	// ��'t'����ʼ��ʱ 
	if(getch() == 't')	
	{		
		printf("�ѿ�ʼ��ʱ...");		// ���ؿ�ʼ��ʱʱ�� 		
		start = clock(); 		// for(;;) ��Ч�� while(1) 		
		for(;;)		
		{		
			ch = getch();			// ��'p'����ͣ��ʱ  		
			if(ch == 'p')
			{			
				for(;;)
				{					// ���ؽ�����ʱʱ�� 				
					end = clock();		
					printf("\n\n����ͣ��ʱ, �ٰ�'p'��ʼ��ʱ. ��ʾ��ǰ��ʱʱ�� : %f\n", 					((double)(end - start) / CLOCKS_PER_SEC));  // CLOCKS_PER_SEC ��Ч�� CLK_TCK, �������ѹ�ʱ 							// �ٴΰ�'p'����ʼ��ʱ 					
					if(getch() == 'p')
					{						
						printf("\n\n������ʱ...");							break;				
			
					}			
			
				}		
			}				// ��'c'��������			
		
			if(ch == 'c')
					
			{				
						printf("\n\n����ѹ���.\n");			
						start = clock(); 		
					
			}			
			// ��'Esc'���˳�����				
					
			if(ch == ESC)			
						break;		
		}	
			
	}
		return 0;
	}		
				
