#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 105;
const int mod = 1e9+7;
LL dp[maxn][2];

int main()
{
	LL n,k,d;
	memset(dp,0,sizeof(dp));
	scanf("%I64d%I64d%I64d",&n,&k,&d);
	dp[0][0] = 1;
	for (int i = 0;i <= n;i++)
	{
		for (int j = 1;j <= k;j++)
		{
			if (i + j > n)	continue;
			if (j < d)	dp[i + j][0] += dp[i][0];
			else dp[i + j][1] += dp[i][0];
			
			dp[i + j][1] += dp[i][1];
			
			dp[i + j][0] %= mod;
			dp[i + j][1] %= mod;
		}
	}
	printf("%I64d\n",dp[n][1]);
	return 0;
}
