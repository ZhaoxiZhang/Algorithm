#include<bits/stdc++.h>
using namespace std; 
const int maxn = 100005;
int fa[maxn],vis[maxn];

void init()
{
	for (int i = 0;i < maxn - 1;i++)	fa[i] = i;
}

int find(int x)
{
	return x == fa[x]?fa[x]:fa[x] = find(fa[x]);
}

void Union(int x,int y)
{
	int fx = find(x),fy = find(y);
	if (fx == fy)	return;
	fa[fx] = fy;
}

int main()
{
	freopen("input.txt","r",stdin);
	int x,y,maxx = 0,minn = maxn,cnt = 0;
	init();
	memset(vis,0,sizeof(vis));
	while (~scanf("%d%d",&x,&y) && x != -1 && y != -1)
	{
		if (!x && !y)
		{
			for (int i = minn;i <= maxx;i++)	if (vis[i] && i == fa[i])	cnt++;
			if (cnt > 1)	printf("No\n");
			else	printf("Yes\n");
			init();
			maxx = 0,minn = maxn;
			cnt = 0;
			memset(vis,0,sizeof(vis));
			continue;
		}
		vis[x] = vis[y] = 1;
		maxx = max(max(x,y),maxx);
		minn = min(min(x,y),minn);
		Union(x,y);
	}
	return 0;
}
