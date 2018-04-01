#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,w,nxt;
}edge[maxn*maxn];
int tot = 0,head[maxn],dis[maxn];
bool vis[maxn];

void addedge(int u,int v,int w)
{
	edge[tot] = (Edge){u,v,w,head[u]
	};
	head[u] = tot++;
}


void spfa(int st,int ed)
{
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	queue<int>que;
	dis[st] = INF;
	que.push(st);
	vis[st] = true;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = head[u];~i;i = edge[i].nxt)
		{
			int v = edge[i].v,w = edge[i].w;
			if (min(dis[u],w) > dis[v])
			{
				dis[v] = min(dis[u],w);
				if (!vis[v])
				{
					que.push(v);
					vis[v] = true;
				}
			}
		}
	}
}

int main()
{
	int tcase;
	scanf("%d",&tcase);
	for (int t = 1;t <= tcase;t++)
	{
		int n,m,u,v,w;
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&m);
		for (int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		} 
		spfa(1,n);
		printf("Scenario #%d:\n",t);
		printf("%d\n",dis[n]);
		if (t != tcase)	printf("\n");
	}
}
