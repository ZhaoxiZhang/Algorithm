#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
int fa[maxn*3];

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

void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (x != y)	fa[x] = y;
}

bool same(int x,int y)
{
	return find(x) == find(y);
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
		for (int i = 0;i <= 3*N;i++)	fa[i] = i;
		while (M--)
		{
			scanf("%s %d %d",opt,&x,&y);
			if (opt[0] == 'A')
			{
				if (find(x) == find(y))
					printf("In the same gang.\n");
				else if (same(x,y + N) && same(x + N,y))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else if (opt[0] == 'D')
			{
				unite(x,y + N);
				unite(x + N,y);
			}
		}
	}
	return 0;
} 
