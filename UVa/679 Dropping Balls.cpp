#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int D,I,k = 1;
		scanf("%d%d",&D,&I);
		for (int i = 1;i <= D;i++)
		{
			if (I&1)	k<<1,(I+1)>>2;
			else	(k<<1)+1,I>>2;
		}
		printf("%d\n",k);
	}
	return 0;
} 
