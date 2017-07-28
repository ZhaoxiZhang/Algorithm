#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int cnt,fa[maxn],num[maxn],sum[maxn],id[maxn];

void init(int N)
{
	for (int i = 0;i <= N;i++)
	{
		fa[i] = id[i] = sum[i] = i;
		num[i] = 1;
	}
	cnt = N;
}

int find(int x)
{
	int r = x;
	while (r != fa[r])	r = fa[r];
	int i = x,j;
	while (i != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
}

void Union(int x,int y)
{
	int fx = find(id[x]),fy = find(id[y]);
	fa[fx] = fy;
	num[fy] += num[fx];
	sum[fy] += sum[fx];
}

void Delete(int x)
{
	int fx = find(id[x]);
	--num[fx];
	sum[fx] -= x;
	id[x] = ++cnt,fa[id[x]] = id[x],num[id[x]] = 1,sum[id[x]] = x;
}

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int opt,x,y;
		init(N);
		while (M--)
		{
			scanf("%d",&opt);
			if (opt == 1)
			{
				scanf("%d%d",&x,&y);
				if (find(id[x]) != find(id[y]))	Union(x,y);
			}
			else if (opt == 2)
			{
				scanf("%d%d",&x,&y);
				if (find(id[x]) != find(id[y]))	Delete(x),Union(x,y);
			}
			else
			{
				scanf("%d",&x);
				printf("%d %d\n",num[find(id[x])],sum[find(id[x])]);
			}
		}
	}
	return 0;
}
