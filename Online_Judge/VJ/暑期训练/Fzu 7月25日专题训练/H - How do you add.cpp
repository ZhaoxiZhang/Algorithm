#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod = 1000000;
const int maxn = 105;
int ans[maxn][maxn];

int main()
{
	int N,K;
	for (int i = 1;i <= maxn;i++)
	{
		ans[1][i] = i;
		ans[i][1] = 1;
	}

	for (int i = 2;i <= 100;i++)
	{
		for (int j = 2;j <= 100;j++)
		{
			ans[i][j] = (ans[i-1][j]%mod + ans[i][j-1]%mod)%mod;
		}
	}
	while (~scanf("%d%d",&N,&K) && N && K)
	{
		printf("%d\n",ans[N][K]);
	}
	return 0;
}
