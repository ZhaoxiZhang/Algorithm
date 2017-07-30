#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		double ans[505] = {0};
		int u,v,val;
		double res = 0;
		for (int i = 1;i <= N;i++)
		{
			scanf("%lf",&ans[i]);
		}
		while (M--)
		{
			scanf("%d%d%d",&u,&v,&val);
			res = max (res,(ans[u]+ans[v])/val);
		}
		printf("%.15lf\n",res);
	}
	return 0;
} 
