#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 105;
int n,a[maxn][maxn],dp[maxn][maxn];

int solve(int i,int j)
{
	if (dp[i][j] >= 0)	return dp[i][j];
	return dp[i][j] = a[i][j] + (i == n ? 0:max(solve(i + 1,j),solve(i + 1,j + 1)));	
}


int main()
{
	//freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;j++)
			scanf("%d",&a[i][j]);
	}
	printf("%d\n",solve(0,0));
	return 0;
} 
