#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const int maxn = 205;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u,v,w,next;
	bool operator < (const Edge &a)const
	{
		return w > a.w;
	}
}edge[maxn*maxn<<1];

struct Point{
	int x,y;
}point[maxn];

int tot = 0,head[maxn],dis[maxn];
bool vis[maxn];

double dist(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void addedge(int u,int v,int w)
{
	edge[tot] = (Edge){u,v,w,head[u]
	};
	head[u] = tot++; 
}

void dijkstra()
{
	priority_queue<Edge>que;
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	Edge p;
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
		for (int i = head[u]; ~i;i = edge[i].next)
		{
			int w = max(edge[i].w,dis[u]);
			int v = edge[i].v;
			if (dis[v] > w)
			{
				dis[v] = w;
				p.u = u,p.v = v,p.w = w;
				que.push(p);
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	int N,tcase = 1;
	while (~scanf("%d",&N) && N)
	{
		memset(head,-1,sizeof(head));
		tot = 0;
		for (int i = 0;i < N;i++)	scanf("%d%d",&point[i].x,&point[i].y);
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				int diss = dist(point[i].x,point[i].y,point[j].x,point[j].y);
				addedge(i + 1,j + 1,diss);
				addedge(j + 1,i + 1,diss);
			}
		}
		dijkstra();
		double res = sqrt(dis[2]);
		printf("Scenario #%d\n",tcase++);
		printf("Frog Distance = %.3f\n\n",res);
	}
	return 0;
}
