#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
LL dp[505][505],w[600];
LL B;
int v[600];
int n;
LL rec(LL i,LL j)
{
	if (dp[i][j] >= 0)
	{
		return dp[i][j];
	}
	LL res;
	if (i == n)
	{
		res = 0;
	}
	else if (j < w[i])
	{
		res = rec(i + 1,j);
	}
	else
	{
		res = max(rec(i + 1,j),rec(i + 1,j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%I64d",&n,&B);
		for (int i = 0;i < n;i++)
		{
			scanf("%I64d%d",&w[i],&v[i]);
		}
		memset(dp,-1,sizeof(dp));
		printf("%I64d\n",rec(0,B));
	}
	return 0;
} 
