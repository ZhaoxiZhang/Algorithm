#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#include<algorithm>
using namespace std;
typedef __int64 LL;
const LL INF = 0x7fffffff ;
const int MAX_V = 1000005;
struct Edge{
	int u,v,w,next;
};

Edge edge1[MAX_V];
Edge edge2[MAX_V];
int dis[MAX_V];
int head1[MAX_V];
int head2[MAX_V];
bool vis[MAX_V];
int P,Q,i;
LL sum = 0;

void init(Edge *edge,int *head,int u,int v,int w)
{
	edge[i].u = u;edge[i].v = v;edge[i].w = w;edge[i].next = head[u];head[u] = i;
}

void spfa(Edge *edge,int *head)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<int>que;
	dis[1] = 0;
	vis[1] = true;
	que.push(1);
	while (!que.empty())
	{
		int curval = que.front();
		que.pop();
		vis[curval] = false;
		for (int i = head[curval];i != -1;i = edge[i].next)
		{
			if (dis[curval] + edge[i].w < dis[edge[i].v])
			{
				dis[edge[i].v] = dis[curval] + edge[i].w;
				if (!vis[edge[i].v])
				{
					vis[edge[i].v] = true;
					que.push(edge[i].v);
				}
			}
		}
	}
	//cout << sum << endl;
	for (int i = 1;i <= P;i++)
	{
		sum += dis[i];
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int u,v,w;
		memset(edge1,0,sizeof(edge1));
		memset(edge2,0,sizeof(edge2));
		memset(head1,-1,sizeof(head1));
		memset(head2,-1,sizeof(head2));
		scanf("%d%d",&P,&Q);
		for (i = 0;i < Q;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			init(edge1,head1,u,v,w);
			init(edge2,head2,v,u,w);
		}
		sum = 0;
		spfa(edge1,head1);
		//cout << sum << endl;
		spfa(edge2,head2);
		printf("%I64d\n",sum);
	}
	return 0;
}


