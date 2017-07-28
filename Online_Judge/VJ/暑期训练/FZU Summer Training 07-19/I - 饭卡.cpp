#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxx = 1005;
int N;
int ans[maxx],dp[maxx][maxx];

int rec(int i,int j)
{
    if (dp[i][j] > -1)
    {
        return dp[i][j];
    }
    int res;
    if (i == N)
    {
        res = 0;
    }
    else if (j < ans[i])
    {
        res = rec(i + 1,j);
    }
    else
    {
        res = max(rec(i + 1,j),rec(i + 1,j - ans[i])+ ans[i]);
    }
    return dp[i][j] = res;
}

int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		int m;
		memset(dp,-1,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&ans[i]);
		}
		sort(ans,ans+N);
		scanf("%d",&m);
		if (m  < 5)
		{
			printf("%d\n",m);
			continue;
		}
		int res = rec(0,m - 5);
		printf("%d\n",m - ans[N-1] - res);
	}
	return 0;
}
