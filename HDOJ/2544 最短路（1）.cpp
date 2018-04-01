#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 10005;

struct Node{
	int u,v,w,next;
}edge[MAX_N];

int head[MAX_N];
int N,M,cnt;


void add(int u,int v,int w)
{
	edge[cnt].u = u;
	edge[cnt].v = v;
 	edge[cnt].w = w;
 	edge[cnt].next = head[u];
 	head[u] = cnt++;
	
	edge[cnt].u = v;
	edge[cnt].v = u;
 	edge[cnt].w = w;
 	edge[cnt].next = head[v];
	head[v] = cnt++;
} 

void spfa()
{
	int dis[MAX_N];
	bool vis[MAX_N];
	queue<int>que;
	
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	
	dis[1] = 0;
	que.push(1);
	vis[1] = true;
	int i;
	while (!que.empty())
	{
		int current = que.front();
		que.pop();
		vis[current] = false;
		
		for (i = head[current]; i != -1; i = edge[i].next)
		{
			if (dis[edge[i].v] > dis[current] + edge[i].w)
			{
				dis[edge[i].v] = dis[current] + edge[i].w;
				if (!vis[edge[i].v])
				{
					que.push(edge[i].v);
					vis[edge[i].v] = true;
				}
			}
		}
	}
	
	printf("%d\n",dis[N]);
}
int main()
{
	while (scanf("%d%d",&N,&M) != EOF && M && N)
	{
		int u,v,w;
		memset(head,-1,sizeof(head));
		cnt = 0;
		
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		spfa();
	}
	return 0;
}
