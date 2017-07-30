#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 LL;
int ans[55];
int N,M;
void init()
{
	for (int i = 1;i <= N;i++)
	{
		ans[i] = i;
	}
}

int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		int u,v;
		LL res = 1;
		memset(ans,0,sizeof(ans));
		init();
		while (M--)
		{
			scanf("%d%d",&u,&v);
			while (u != ans[u])
			{
				u = ans[u];
			}
			while (v != ans[v])
			{
				v = ans[v];
			}
			if (u != v)
			{
				res *= 2;
			}
			ans[v] = u;
		}
		printf("%I64d\n",res);
	}
	return 0;
}
