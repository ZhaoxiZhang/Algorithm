#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 30005;
int fa[maxn],top[maxn],size[maxn];

int find(int x)
{
	if (fa[x] == x)	return fa[x];
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	top[x] += top[tmp];
	return fa[x];
}

void Union(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx == fy)	return;
	fa[fy] = fx;
	top[fy] = size[fx];
	size[fx] += size[fy];
} 


int main()
{
	int P,x,y;
	char opt[5];
	for (int i = 0;i < maxn;i++)	fa[i] = i,size[i] = 1,top[i] = 0;
	scanf("%d",&P);
	while (P--)
	{
		scanf("%s",opt);
		if (opt[0] == 'M')
		{
			scanf("%d%d",&x,&y);
			Union(x,y);
		}
		if (opt[0] == 'C')
		{
			scanf("%d",&x);
			int fx = find(x);
			printf("%d\n",size[fx] - top[x] - 1);
		} 
	}
	return 0;
} 
