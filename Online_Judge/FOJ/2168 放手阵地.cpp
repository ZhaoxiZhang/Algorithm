#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[1000005],sum[1000005];

int main()
{
	int N,M,max;
	
	while (scanf("%d%d",&N,&M) != EOF)
	{
		max = 0;
		memset(sum,0,sizeof(sum));
		
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		
		for (int i = 0;i <= N - M;i++)
		{
			for (int j = 0;j < M;j++)
			{
				sum[i] += ans[i+j] * (j + 1);
			}
			
			if (sum[i] > max)
			{
				max = sum[i];
			}
		}
		
		printf("%d\n",max);
	}
	
	return 0;
}
