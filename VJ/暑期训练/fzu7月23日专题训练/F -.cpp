#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = (105*105-105)/2;
struct Edge{
	int u,v,w;
};
int N,father[MAX],rk[MAX];
struct Edge edge[MAX];

bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}


void init()
{
	memset(father,0,sizeof(father));
	memset(rk,0,sizeof(rk));
	for (int i = 0;i <= N;i++)
	{
		father[i] = i;
	}
}

int find(int x)
{
	int r = x;
	while (father[r] != r)
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
/*int find(int x)
{
	return x == father[x]?x:father[x] = find(father[x]);
}*/

void unite(int x,int y)
{
	int fx,fy;
	fx = find(x);
	fy = find(y);
	if (fx == fy)	return;
		if (rk[fx] < rk[fy])
		{
			father[fx] = fy;
		}
		else
		{
			father[fy] = fx;
			if (rk[x] == rk[y])
			{
				rk[x]++;
			}
		}
	
}

/*void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx != fy)
	{
		father[fx] = fy;
	}
}*/


int main()
{
	while (~scanf("%d",&N))
	{
		int tmp,cnt = 0,sum = 0;
		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				scanf("%d",&tmp);
				if (i < j)
				{
					edge[cnt].u = i;
					edge[cnt].v = j;
					edge[cnt].w = tmp;
					cnt++;
				}
			}
		}
		init();
		sort(edge,edge+cnt,cmp);
		for (int i = 0;i < cnt;i++)
		{
			int x,y;
			x = find(edge[i].u);
			y = find(edge[i].v);
			if (x != y)
			{
				unite(x,y);
				sum += edge[i].w;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
