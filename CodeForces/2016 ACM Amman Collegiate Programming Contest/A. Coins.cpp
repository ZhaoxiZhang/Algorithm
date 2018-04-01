#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
const int mod = 1e9+7;
int dp[2][15500];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m,k,w;
		scanf("%d%d%d%d",&n,&m,&k,&w);
		memset(dp,0,sizeof(dp));
		dp[0][0] = dp[1][0] = 1;
		for (int i = 1;i <= n;i++)
		{
			int x;
			scanf("%d",&x);
			for (int j = w;j >= x;j--)
			{
				dp[0][j] += dp[0][j-x];
				while (dp[0][j] >= mod)	dp[0][j] -= mod; 
			}
		}
		for (int i = 1;i <= n;i++)
		{
			int x;
			scanf("%d",&x);
			for (int j = w;j >= x;j--)
			{
				dp[0][j] += dp[1][j-x];
				while (dp[0][j] >= mod)	dp[1][j] -= mod; 
			}
		}
		LL ans = 0;
		for (int i = 0;i <= w;i++)
		{
			if (abs(w-i-i) <= k)	ans = (ans + (LL)dp[0][w-i]*dp[1][i])%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
