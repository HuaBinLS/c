 #include"stdio.h"
int main()
{
	int a,b,c,f,i,z;
	b=0;
	c=0;
	f=0;
	i=0;
	z=0;
	for(a=0;a<2;a++)
	{
		if(a==1)
		{
			b=b+1;
			if(b==20)
			{
				i=i+1;			
				b=0;
				a=0;
				if(i==10)
				{
					z=z+1;
					i=0;
					printf("%d%d:%d%d.%d",f,c,z,i,b);
					system("cls");
				}
				if(z==6)
				{
					c=c+1;
					z=0;
					printf("%d%d:%d%d.%d",f,c,z,i,b);
					system("cls");
				}
				if(c==10)
				{
					f=f+1;
					c=0;
					i=0;
					printf("%d%d:%d%d.%d",f,c,z,i,b);
					system("cls");
				}
				printf("%d%d:%d%d.%d",f,c,z,i,b);
				system("cls");
			}
			a=0; 
			printf("%d%d:%d%d.%d",f,c,z,i, b);
			system("cls");
		}
	}
	

} 
