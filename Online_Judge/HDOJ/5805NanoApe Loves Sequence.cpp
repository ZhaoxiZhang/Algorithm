#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef __int64 LL;
int num[maxn],f[maxn],g[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		scanf("%d",&N);
		scanf("%d",&num[1]);
		f[0] = 0;
		for (int i = 2;i <= N;i++)
		{
			scanf("%d",&num[i]);
			f[i] = max(f[i-1],abs(num[i] - num[i-1]));
		}
		g[N] = 0;
		for (int i = N - 1;i > 0;i--)
		{
			g[i] = max(g[i+1],abs(num[i+1] - num[i]));
		} 
		LL res = 0;
		for (int i = 2;i < N;i++)
		{
			res += max(abs(num[i-1]-num[i+1]),max(f[i-1],g[i+1]));
		}
		res += g[2] + f[N-1];
		printf("%I64d\n",res);
	} 
	return 0;
}
