#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
int fa[maxn],r[maxn];

int find(int x)
{
	if (fa[x] == x)	return fa[x];
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	r[x] = (r[tmp] + r[x]) % 2;
	return fa[x];
}

void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx == fy)	return;
	fa[fy] = fx;
	r[fy] = (r[x] + 1 - r[y]) % 2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,M,x,y;
		char opt[5];
		scanf("%d%d",&N,&M);
		for (int i = 0;i <= N;i++)	fa[i] = i,r[i] = 0;
		while (M--)
		{
			scanf("%s %d %d",opt,&x,&y);
			if (opt[0] == 'A')
			{
				if (find(x) == find(y))
				{
					if (r[x] == r[y])	printf("In the same gang.\n");
					else	printf("In different gangs.\n");
				}
				else	printf("Not sure yet.\n");
			} 
			else	unite(x,y);
		}
	}
	return 0;
}
