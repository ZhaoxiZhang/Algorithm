#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1005;
struct Edge{
	int u,v,w;
}edge[maxn*maxn/2];
int fa[maxn];

bool cmp(Edge a,Edge b)
{
	return a.w > b.w;
}

int find(int x)
{
	return fa[x] == x?fa[x]:fa[x] = find(fa[x]);
}

void Union(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx != fy)	fa[fx] = fy;
}

int main()
{
	int tcase;
	scanf("%d",&tcase);
	for (int t = 1;t <= tcase;t++)
	{
		int n,m,res = 0x3f3f3f3f;
		scanf("%d%d",&n,&m);
		for (int i = 0;i <= n;i++)	fa[i] = i;
		for (int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		sort(edge,edge + m,cmp);
		for (int i = 0; i< m;i++)
		{
			Union(edge[i].u,edge[i].v);
			if (find(1) == find(n))
			{
				res = edge[i].w;
				break;
			}
		}
		printf("Scenario #%d:\n",t);
		printf("%d\n",res);
		if (t != tcase)	printf("\n");
	}
	return 0;
} 
