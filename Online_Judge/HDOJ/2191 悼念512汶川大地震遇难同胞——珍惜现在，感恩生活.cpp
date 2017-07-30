#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int dp[maxn] = {0},p[maxn] = {0},h[maxn] = {0},c[maxn] = {0};
		int w[550] = {0},v[550] = {0};
		int n,m,index = 0;
		scanf("%d%d",&n,&m);
		for (int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&p[i],&h[i],&c[i]);
			//利用二进制思想，拆分物品，转换为01背包 
			for (int j = 1;j <= c[i]; j<<=1)
			{
				w[index] = j*h[i];
				v[index++] = j*p[i];
				c[i] -= j;
			}
			//无法正好拆分的作为自己一个整体 
			if (c[i] > 0)
			{
				w[index] = c[i]*h[i];
				v[index++] = c[i]*p[i];
			}
		}	
		for (int i = 0;i < index;i++)
		{
			for (int j = n;j >= v[i];j--)
			{
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
} 
