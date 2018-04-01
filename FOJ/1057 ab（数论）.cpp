#include<stdio.h>
typedef __int64 LL;

int main()
{
	LL a,b;
	while (~scanf("%I64d%I64d",&a,&b) && a && b)
	{
		LL M = 1;
		for (LL i = 0;i < b;i++)
		{
			M = M * a % 9;
		}
		if (!M)
		{
			printf("9\n");
		}
		else
		{
			printf("%I64d\n",M);
		}
	}
	return 0;
} 
