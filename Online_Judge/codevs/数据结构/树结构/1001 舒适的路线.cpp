#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 5005;
const int INF = 0x3f3f3f3f;
int N,M,rk[maxn],father[maxn];

struct Edge{
	int u,v,w;
}edge[maxn];

bool cmp(struct Edge x,struct Edge y)
{
	return x.w < y.w;
}

void init()
{
	memset(rk,0,sizeof(rk));
	memset(father,0,sizeof(father));
	for (int i = 0;i <= N;i++)
	{
		father[i] = i;
	}
}

int find(int x)
{
	int r = x;
	while (r != father[r])
	{
		r = father[r];
	}
	int i = x,j;
	while (i != r)
	{
		j = father[i];
		father[i] = r;
		i = j;
	}
	return r;
}

void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		if (rk[x] < rk[y])
		{
			father[x] = y;
		}
		else
		{
			father[y] = x;
			if (rk[x] == rk[y])
			{
				rk[x]++;
			}
		}
	}
}

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		int s,t,fz,fm;
		double res = INF;
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		scanf("%d%d",&s,&t);
		sort(edge,edge + M,cmp);
		for (int i = 0;i < M;i++)
		{
			init();
			for (int j = i;j < M;j++)
			{
				unite(edge[j].u,edge[j].v);
				if (find(s) == find(t))
				{
					double tmp = 1.0*edge[j].w/edge[i].w;
					if (tmp < res)
					{
						res = tmp;
						fz = edge[j].w;
						fm = edge[i].w;
					}
				}
			}
		}
		int com = gcd(fz,fm);
		res == INF?printf("IMPOSSIBLE\n"):fm/com == 1?printf("%d\n",fz/com):printf("%d/%d\n",fz/com,fm/com);
	}
	return 0;
}
