/*
 *dp[i][j]表示时刻i，在车站j，最少还需要等待多长时间
 *has_train[t][i][0]表示时刻t，在车站i是否有向右开的火车
 *has_train[t][i][1]表示时刻t，在车站i是否有向左开的火车
 */ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 55;
const int maxt = 205;
const int INF = 0x3f3f3f3f;
int t[maxn],has_train[maxt][maxn][2],dp[maxt][maxn];
int main()
{
	int n,Case = 0;
	while (~scanf("%d",&n) && n)
	{
		int T,M1,M2,d;
		memset(has_train,0,sizeof(has_train));
		memset(dp,0,sizeof(dp));
		scanf("%d",&T);
		for (int i = 1;i < n;i++)	scanf("%d",&t[i]);
		scanf("%d",&M1);
		while (M1--)
		{
			scanf("%d",&d);
			for (int j = 1;j < n;j++)
			{
				if (d <= T)	has_train[d][j][0] = 1;
				d += t[j]; 
			}
		} 
		scanf("%d",&M2);
		while (M2--)
		{
			scanf("%d",&d);
			for (int j = n - 1;j > 0;j--)
			{
				if (d <= T)	has_train[d][j+1][1] = 1;
				d += t[j];
			}
		}
		for (int i = 1;i < n;i++)	dp[T][i] = INF;
		dp[T][n] = 0;
		for (int i = T - 1;i >= 0;i--)
		{
			for (int j =1;j <= n;j++)
			{
				dp[i][j] = dp[i+1][j] + 1;
				if (j < n && has_train[i][j][0] && i + t[j] <= T)	dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]);
				if (j > 1 && has_train[i][j][1] && i + t[j-1] <= T)	dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);
			}
		}
		printf("Case Number %d: ",++Case);
		dp[0][1]>=INF ? printf("impossible\n"):printf("%d\n",dp[0][1]);
	}
	return 0;
}
