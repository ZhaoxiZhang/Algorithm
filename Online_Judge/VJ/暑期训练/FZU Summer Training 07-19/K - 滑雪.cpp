#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dp[105][105],ans[105][105];
int R,C;

int dfs(int x,int y)
{
	if (dp[x][y] != -1)	return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx <= R && ny > 0 && ny <= C && ans[nx][ny] < ans[x][y] && dp[x][y] < dfs(nx,ny)+1)
		{
			dp[x][y] = dp[nx][ny] + 1;
		}
	} 
	return dp[x][y];
	
}

int main()
{
	while (~scanf("%d%d",&R,&C))
	{
		int res = 0;
		memset(ans,0,sizeof(ans));
		memset(dp,-1,sizeof(dp));
		for (int i = 1;i <= R;i++)
		{
			for (int j = 1;j <= C;j++)
			{
				scanf("%d",&ans[i][j]);
			}
		}
		for (int i = 1;i <= R;i++)
		{
			for (int j = 1;j <= C;j++)
			{
				res = max(res,dfs(i,j));
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
