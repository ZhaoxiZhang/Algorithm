#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
int c[maxn],v[maxn];
int dp[1000005];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,M;
		memset(dp,0,sizeof(dp)); 
		scanf("%d%d",&N,&M);
		for (int i = 1;i <= N;i++)	scanf("%d%d",&c[i],&v[i]);
		for (int i = 1;i <= N;i++)
		{
			int tmp = 0;
			for (int j = i + 1;j <= N;j++)	tmp += c[j];
			tmp = max(M-tmp,c[i]);      //01背包常数级优化 
			for (int j = M;j >= tmp;j--)
			{
				dp[j] = max(dp[j],dp[j-c[i]]+v[i]);
			}
		}
		printf("Max experience: %d\n",dp[M]);
	}
	return 0; 
} 
