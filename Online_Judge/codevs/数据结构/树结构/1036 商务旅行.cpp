#include<bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int tot = 0,road[maxn],dis[maxn],flag[maxn],vis[maxn],head[maxn],fa[maxn],ancestor[maxn];
struct Edge{
	int to,next;
}edge[maxn<<1];

int tt = 0,h[maxn],answer[maxn];
struct Query{
	int q,next;
	int index;
}qry[maxn<<1];

void init(int N)
{
	for (int i = 0;i <= N;i++)
	{
		fa[i] = i;ancestor[i] = 0;
		vis[i] = false;
		head[i] = h[i] = -1;
	}
}


void addedge(int u,int v)
{
	edge[tot] = (Edge){v,head[u]};
	head[u] = tot++;
}

void add_query(int u,int v,int index)
{
	qry[tt] = (Query){v,h[u],index};
	h[u] = tt++;
	qry[tt] = (Query){u,h[v],index};
	h[v] = tt++;
}

void spfa()
{
	queue<int>que;
	memset(dis,0x3f,sizeof(dis));
	memset(flag,false,sizeof(flag));
	que.push(1);
	dis[1] = 0;
	flag[1] = true;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		flag[u] = false;
		for (int i = head[u];i != -1;i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[u] + 1 < dis[v])
			{
				dis[v] = dis[u] + 1;
				if (!flag[v])
				{
					que.push(v);
					flag[v] = true;
				}
			}
		}
	}
}

int find(int x)
{
	int r = x;
	while (r != fa[r])	r = fa[r];
	int i = x,j;
	while (i != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
}

void Union(int x,int y)
{
	x = find(x),y = find(y);
	if (x == y)	return;
	fa[y] = x;
}

void targin_LCA(int u)
{
	ancestor[u] = u;
	vis[u] = true;
	for (int i = head[u]; i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (vis[v])	continue;
		targin_LCA(v);
		Union(u,v);
		ancestor[find(u)] = u;
	}
	for (int i = h[u];i != -1;i = qry[i].next)
	{
		int v = qry[i].q;
		if (vis[v])
		{
			answer[qry[i].index] = ancestor[find(v)];
		}
	}
	
}

int main()
{
	int N,M,u,v,sum = 0;
	scanf("%d",&N);
	init(N);
	for (int i = 1;i < N;i++)
	{
		scanf("%d%d",&u,&v); 
		addedge(u,v);
		addedge(v,u);
	}
	spfa();
	scanf("%d",&M);
	scanf("%d",&road[0]);
	for (int i = 1;i < M;i++)	scanf("%d",&road[i]),add_query(road[i-1],road[i],i);
	targin_LCA(1);
	for (int i = 1;i < M;i++)
	{
		sum += dis[road[i]] + dis[road[i-1]] - 2*dis[answer[i]];
	}
	printf("%d\n",sum);
	return 0;
}
