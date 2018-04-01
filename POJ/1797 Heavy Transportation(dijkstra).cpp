#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,w,nxt;
	bool operator < (const Edge &a)const
	{
		return w < a.w;
	}
}edge[maxn*maxn];
int tot = 0,head[maxn],dis[maxn];
bool vis[maxn];

void addedge(int u,int v,int w)
{
	edge[tot] = (Edge){u,v,w,head[u]
	};
	head[u] = tot++;
}

void dijkstra(int st,int n)
{
	Edge p;
	priority_queue<Edge>que;
	memset(dis,0,sizeof(dis));
	memset(vis,false,sizeof(vis));
	p.v = st;
	p.w = INF;
	dis[st] = INF;
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		int u = p.v;
		if (vis[u])	continue;
		vis[u] = true;
		for (int i = head[u];~i;i = edge[i].nxt)
		{
			int v = edge[i].v,w = edge[i].w;
			if (dis[v] < min(dis[u],w))
			{
				dis[v] = min(dis[u],w);
				p.v = v,p.w = dis[v];
				que.push(p); 
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
		dijkstra(1,n);
		printf("Scenario #%d:\n",t);
		printf("%d\n",dis[n]);
		if (t != tcase)	printf("\n");
	}
	return 0;
	
} 
