#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N,res = 0;
	int dp[1005] = {0},ans[1005] = {0};
	scanf("%d",&N);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d",&ans[i]);
	}
	for (int i = 1;i <= N;i++)
	{
		dp[i] = 1;
		for (int j = 1;j < i;j++)
		{
			if (ans[j] < ans[i] && dp[i] < dp[j]+1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		res = max(res,dp[i]);
	}
	
	printf("%d\n",res);
	return 0;
}
