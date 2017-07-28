#include<stdio.h>
const int maxn =  50005;
int r[maxn],fa[maxn];

int find(int x)
{
	if (x == fa[x])	return fa[x];
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	r[x] = (r[x] + r[tmp])%3;
	return fa[x];
}

void unite(int x,int y,int d)
{
	int fx = find(x),fy = find(y);
	fa[fy] = fx;             //y被x吃，所以以x作为y的根节点
	r[fy] = (r[x] - r[y] + 3 + (d - 1))%3; 
}

int main()
{
	int N,K,X,Y,D,res = 0;
	scanf("%d%d",&N,&K);
	for (int i = 1;i <= N;i++)	r[i] = 0,fa[i] = i;
	while (K--)
	{
		scanf("%d%d%d",&D,&X,&Y);
		if (X > N || Y > N ||(X == Y && D == 2))	res++;
		else if (find(X) == find(Y))
		{
			if (D == 1 && r[X] != r[Y])	res++;
			if (D == 2 && (r[X] + 1) % 3 != r[Y])	res++;
		}
		else unite(X,Y,D);
	}
	printf("%d\n",res);
	return 0;
}
