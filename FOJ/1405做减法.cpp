#include<stdio.h>

int main()
{
	int x,y,dif;
	
	while (scanf("%d%d",&x,&y) != EOF)
	{
		dif = x - y;
		if (dif < 0)
		{
			printf("-");
			dif = -dif;
		}
		
		if (dif >= 1000000000)
		{
			printf("%d,%03d,%03d,%03d\n",dif/1000000000,(dif/1000000)%1000,(dif/1000)%1000,dif%1000000); 
		}
		else if (dif >= 1000000)
		{
			printf("%d,%03d,%03d\n",dif/1000000,(dif/1000)%1000,dif%1000);
		}
		else if (dif >= 1000)
		{
			printf("%d,%03d\n",dif/1000,dif%1000);
		}
		else
		{
			printf("%d\n",dif);
		}
	}
	
	return 0;
}
