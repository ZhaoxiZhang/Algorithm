#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct Node{
	int x,y;
}node[maxn];
int fa[maxn];

int find(int x)
{
	return fa[x] == x?fa[x]:find(fa[x]);
}

void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx == fy)	return;
	fa[fy] = fx;
} 

int main()
{
	int n,res = 0;
	for (int i = 0;i < maxn;i++)	fa[i] = i;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)	scanf("%d%d",&node[i].x,&node[i].y);
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			if (node[i].x == node[j].x || node[i].y == node[j].y)
			{
				unite(i,j);
			}
		}
	}
	for (int i = 1;i <= n;i++)	if (find(i) == i)	res++;
	printf("%d\n",res - 1);
	return 0;
}
