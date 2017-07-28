#include<stdio.h>
int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[35] = {0};
		int i = 0;
		while (N)
		{
			ans[i++] = N % 2;
			N /= 2;
		}
		for (i -= 1;i >= 0;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
} 
