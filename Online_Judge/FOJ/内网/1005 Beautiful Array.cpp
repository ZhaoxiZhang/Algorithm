#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		__int64 ans[1005];
		__int64 dp[1005][6];
		memset(dp,0,sizeof(dp));
		int N;
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&ans[i]);
			dp[i][1] = 1;
			for (int k = 0;k < i;k++)
			{
				if (ans[k] < ans[i])
				{
					for (int j = 2;j <= 5;j++)
					{
						dp[i][j] += dp[k][j-1];
					}
				}
			} 
		}
		__int64 sum = 0;
		for (int i = 0;i < N;i++)
		{
			sum += dp[i][5];
		}
		printf("%I64d\n",sum);
	}
	return 0;
} 
