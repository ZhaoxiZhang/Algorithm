#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn];

int main()
{
	int n,m,k;
	while (~scanf("%d%d%d",&n,&m,&k))
	{
		int u,v,tmp,pos = 1;
		bool flag = false;
		memset(a,0,sizeof(a));
		for (int i = 0;i < m;i++)
		{
			scanf("%d",&tmp);
			a[tmp] = 1;
		}
		if (a[1] == 1)	flag = true;
		for (int i = 0;i < k;i++)
		{
			scanf("%d%d",&u,&v);
			if (flag)	continue;
			if (pos == u)
			{
				pos = v;
				if (a[v] == 1)	flag = true;
			}
			else if (pos == v)
			{
				pos = u;
				if (a[u] == 1)	flag = true;
			}
		}
		printf("%d\n",pos);
	}
	return 0;
}
