#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int A,B,C,D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		int sum = B + D;
		printf("%d %d\n%d %d\n",C,sum,A,sum);
	}
	return 0;
} 
