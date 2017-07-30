#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,w,next;
	bool operator < (const Edge &x)const 
	{
		return w > x.w;
	}
}edge[maxn*(maxn-1)];
int tot = 0,head[maxn],dis[maxn];
bool vis[maxn];

void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
} 

void addedge(int u,int v,int w)
{
	edge[tot] = (Edge){u,v,w,head[u]
	};
	head[u] = tot++;
}

int prim()
{
	int sum = 0;
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
		sum += dis[u];
		for (int i = head[u];~i;i = edge[i].next)
		{
			int v = edge[i].v,w = edge[i].w;
			if (dis[v] > w)
			{
				dis[v] = edge[i].w;
				p.u = u,p.v = v,p.w = w;
				que.push(p);
			}
		}
	}
	return sum;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int N;
	while (~scanf("%d",&N) && N)
	{
		int u,v,w;
		int len = N*(N - 1)/2;
		init();
		for (int i = 0;i < len;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		printf("%d\n",prim());
	}
	return 0;
}
