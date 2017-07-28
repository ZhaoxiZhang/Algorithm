#include<stdio.h>
#include<string.h>
const int maxn = 50005;
int N,fa[maxn*3];

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
	int K,D,X,Y,res = 0;
	scanf("%d%d",&N,&K);
	for (int i = 1;i <= 3*N;i++)	fa[i] = i;
	while (K--)
	{
		scanf("%d%d%d",&D,&X,&Y);
		if (X < 1 || X > N || Y < 1 || Y > N)
		{
			res++;
			continue;
		}
		if (D == 1)
		{
			if (same(X,Y+N) || same(X,Y+2*N))	res++;
			else	unite(X,Y),unite(X+N,Y+N),unite(X+2*N,Y+2*N);
		}
		else if (D == 2)
		{
			if (same(X,Y) || same(X,Y+2*N))	res++;
			else	unite(X,Y+N),unite(X+N,Y+2*N),unite(X+2*N,Y);
		}
	}
	printf("%d\n",res);
	return 0;
} 
