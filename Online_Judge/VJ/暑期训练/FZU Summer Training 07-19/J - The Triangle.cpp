#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
LL N;
LL ans[105][105] = {0};
LL dp[105][105] = {0};

LL solve (LL i,LL j)
{
	if (dp[i][j] > -1)	return dp[i][j];
	return dp[i][j] = ans[i][j] + (i == N?0:max(solve(i+1,j),solve(i+1,j+1)));
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%I64d",&N);
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			scanf("%I64d",&ans[i][j]);
		}
	}
	printf("%I64d\n",solve(1,1));
	return 0;
} 
