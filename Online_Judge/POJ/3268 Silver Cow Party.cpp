#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1005;
const int maxm = 100005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,w,nxt;
}edge1[maxm],edge2[maxm];
int tot = 0,head1[maxn],head2[maxn],dis1[maxn],dis2[maxn];
bool vis[maxn];

void addedge(Edge *edge,int *head,int u,int v,int w)
{
	edge[tot] = (Edge){u,v,w,head[u]
	};
	head[u] = tot++;
}

void spfa(Edge *edge,int *head,int *dis,int st)
{
	queue<int>que;
	memset(vis,false,sizeof(vis));
	dis[st] = 0;
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
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
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
	//freopen("input.txt","r",stdin);
	int N,M,X,u,v,w;
	memset(dis1,INF,sizeof(dis1));
	memset(dis2,INF,sizeof(dis2));
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2)); 
	scanf("%d%d%d",&N,&M,&X);
	for (int i = 0;i < M;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(edge1,head1,u,v,w);
		addedge(edge2,head2,v,u,w);
	}
	spfa(edge1,head1,dis1,X);
	spfa(edge2,head2,dis2,X);
	int res = 0;
	for (int i = 1;i <= N;i++)
	{
		res = max(res,dis1[i] + dis2[i]);
	}
	printf("%d\n",res);
	return 0;
}
