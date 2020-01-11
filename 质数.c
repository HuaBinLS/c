#include"stdio.h"
int main()
{
	int a,b;
	//取0-99的数
	for(a=1;a<100;a++)
	{
		//让a除b求余
		for(b=2;b<=a;b++)
		{
			//判定a是否能被其他数所整除
			if(a%b==0)
			{
				//结束该循环，进入下一步
				break;
			}
		}
		//判定ab是否相等
		if(a==b)
		{
			printf("%d ",a);
		}
	}
	system("pause");
}