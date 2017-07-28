#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int maxn = 2005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,next;
	LL w;
	bool operator < (const Edge & a)const
	{
		return w > a.w;
	}
}edge[maxn<<1] ;
int tot = 0,head[maxn];
bool vis[maxn];
LL dis[maxn];

void addedge(int u,int v,LL w)
{
	edge[tot] = (Edge){u,v,head[u],w
	};
	head[u] = tot++;
}

void Dijkstra()
{
	priority_queue<Edge>que;
	Edge p; 
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis)); 
	p.v = 1;
	que.push(p);
	dis[1] = 0;
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		int u = p.v;
		if (vis[u])	continue;
		vis[u] = true;
		for (int i = head[u];i != -1;i = edge[i].next)
		{
			int v = edge[i].v;
			if (dis[u] + edge[i].w < dis[v])
			{
				dis[v] = dis[u] + edge[i].w;
				p.u = u,p.v = v,p.w = dis[v];
				que.push(p);
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T,N,u,v;
	LL w;
	memset(head,-1,sizeof(head)); 
	scanf("%d%d",&T,&N);
	for (int i = 0;i < T;i++)
	{
		scanf("%d%d%I64d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	Dijkstra();
	printf("%I64d\n",dis[N]);
	return 0;
} 
