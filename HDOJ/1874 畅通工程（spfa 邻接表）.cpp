#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct Edge{
	int u,v,w,next;
}; 

Edge edge[2005];

const int INF = 0x3f3f3f3f;
int dis[2005];
int head[2005];
int vis[2005];

void spfa(int s)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>que;
	dis[s] = 0;
	vis[s] = 1;
	que.push(s);
	while (!que.empty())
	{
		int curval = que.front();
		que.pop();
		vis[curval] = 0;
		for (int i = head[curval];i != -1;i = edge[i].next)
		{
			if (dis[curval]+edge[i].w < dis[edge[i].v])
			{
				dis[edge[i].v] = dis[curval] + edge[i].w;
				if (!vis[edge[i].v])
				{
					vis[edge[i].v] = 1;
					que.push(edge[i].v);
				}
			}
		}
	}
}




int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int u,v,w,s,t;
		memset(head,-1,sizeof(head));
		for (int i = 0;i < 2*M;i+=2)
		{
			scanf("%d%d%d",&u,&v,&w);
			edge[i].u = u;edge[i].v = v;edge[i].w = w;edge[i].next = head[u];head[u] = i;
			edge[i+1].u = v;edge[i+1].v = u;edge[i+1].w = w;edge[i+1].next = head[v];head[v] = i+1;
		}
		scanf("%d%d",&s,&t);
		spfa(s);
		printf("%d\n",dis[t] == INF?-1:dis[t]);
	}
	return 0;
}
