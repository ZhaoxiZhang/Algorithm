#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,u,v;
		__int64 res = 0;
		int ans[10005] = {0};
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
		}
		while (--N)
		{
			scanf("%d%d",&u,&v);
			res += min(ans[u],ans[v]);
		}
		printf("%I64d\n",res);
	}
	return 0;
}
